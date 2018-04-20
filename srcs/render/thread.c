/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:27:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 17:12:37 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			*loading(void *data)
{
	t_thread_arg	*thread_arg;
	int				i;
	t_vector		col;
	int				x;
	int				y;

	thread_arg = (t_thread_arg*)data;
	col = new_vector(1, 1, 1);
	i = 0;
	x = -1;
	while (!thread_arg->end)
	{
		pthread_cond_wait(&thread_arg->progress, &thread_arg->mutex);
		x = -1;
		while (++x < WIN_WIDTH / LOADING_STEP)
		{
			y = WIN_HEIGH - 16;
			while (++y < WIN_HEIGH)
				put_pixel(thread_arg->img->loading_img_buffer, x + i, y, &col);
		}
		mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
								thread_arg->img->loading_img_ptr, 0, 0);
		i += WIN_WIDTH / LOADING_STEP;
	}
	pthread_exit(NULL);
}

static void		init_thread_arg(t_thread_arg *thread_arg, t_ray *ray,
													t_env *env, t_img *img)
{
	thread_arg->ray = ray;
	thread_arg->env = env;
	thread_arg->img = img;
	thread_arg->thread_num = 0;
	thread_arg->end = 0;
	ray->ori.x = env->camera->pos.x;
	ray->ori.y = env->camera->pos.y;
	ray->ori.z = env->camera->pos.z;
}

void			draw_img(t_img *img, t_env *env, int i)
{
	t_ray			ray;
	t_thread_arg	thread_arg;
	pthread_t		*thread;

	(!(thread = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_THREADS + 1)))
														? exit(-1) : 0;
	init_thread_arg(&thread_arg, &ray, env, img);
	init_camera(env->camera, (float)WIN_WIDTH / (float)WIN_HEIGH);
	(pthread_create(&thread[NUMBER_OF_THREADS], NULL, loading,
										&thread_arg) != 0) ? exit(3) : 0;
	pthread_mutex_init(&thread_arg.mutex, NULL);
	pthread_cond_init(&thread_arg.progress, NULL);
	while (++i < NUMBER_OF_THREADS)
		(pthread_create(&thread[i], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	i = -1;
	while (++i < NUMBER_OF_THREADS)
		pthread_join(thread[i], NULL);
	thread_arg.end = 1;
	pthread_cond_signal(&thread_arg.progress);
	pthread_join(thread[NUMBER_OF_THREADS], NULL);
	free(thread);
	save_image(env->camera, img->buffer);
}
