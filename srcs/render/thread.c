/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:27:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 22:12:12 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		*loading(void *data)
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
		printf("load...\n");
		mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
								thread_arg->img->loading_img_ptr, 0, 0);
		mlx_do_sync(thread_arg->img->mlx);
		i += WIN_WIDTH / LOADING_STEP;
	}
	printf("rendered...\n");
	mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
													thread_arg->img->ptr, 0, 0);
	mlx_do_sync(thread_arg->img->mlx);
	printf("sync done...\n");
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

static void		*wait_fnc(void *data)
{
	t_thread_arg	*thread_arg;
	int				i;

	thread_arg = (t_thread_arg*)data;
	i = -1;
	while (++i < NUMBER_OF_THREADS)
		pthread_join(thread_arg->thread[i], NULL);
	thread_arg->end = 1;
	pthread_cond_signal(&thread_arg->progress);
	save_image(thread_arg->env->camera, thread_arg->img->buffer);
	pthread_exit(NULL);
}

void			draw_img(t_img *img, t_env *env, int i)
{
	t_ray			ray;
	t_thread_arg	thread_arg;
	pthread_t		thread[NUMBER_OF_THREADS + 2];

	init_thread_arg(&thread_arg, &ray, env, img);
	thread_arg.thread = thread;
	init_camera(env->camera, (float)WIN_WIDTH / (float)WIN_HEIGH);
	(pthread_create(&thread[NUMBER_OF_THREADS], NULL, loading,
										&thread_arg) != 0) ? exit(3) : 0;
	pthread_mutex_init(&thread_arg.mutex, NULL);
	pthread_cond_init(&thread_arg.progress, NULL);
	while (++i < NUMBER_OF_THREADS)
		(pthread_create(&thread[i], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	(pthread_create(&thread[NUMBER_OF_THREADS + 1], NULL, wait_fnc,
										&thread_arg) != 0) ? exit(3) : 0;
	mlx_loop(img->mlx);
}
