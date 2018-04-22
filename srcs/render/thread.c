/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:27:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 11:33:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		loading(int	*loading_img_buffer, int reset)
{
	static int		i = 0;
	t_vector		col;
	int				x;
	int				y;

	if (reset)
	{
		i = 0;
		twl_bzero(loading_img_buffer, WIN_WIDTH * WIN_HEIGH * 4);
	}
	else
	{
		col = new_vector(1, 1, 1);
		x = -1;
		while (++x < WIN_WIDTH / LOADING_STEP)
		{
			y = WIN_HEIGH - 16;
			while (++y < WIN_HEIGH)
				put_pixel(loading_img_buffer, x + i, y, &col);
		}
		i += WIN_WIDTH / LOADING_STEP;
	}
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
	if (thread_arg->env->camera->save_as_ppm)
		save_image(thread_arg->env->camera, thread_arg->img->buffer);
	pthread_exit(NULL);
}

void			draw_img(t_img *img, t_env *env, int i)
{
	t_ray			ray;
	t_thread_arg	thread_arg;
	pthread_t		thread[NUMBER_OF_THREADS + 1];
	t_clean_arg		clean_arg;

	init_thread_arg(&thread_arg, &ray, env, img);
	mlx_loop_hook(img->mlx, flip, &thread_arg);
	clean_arg.img = img;
	clean_arg.env = env;
	clean_arg.end = &thread_arg.end;
	mlx_hook(img->win, 17, 0, clean_quit, &clean_arg);
	mlx_key_hook(img->win, key_hook, &clean_arg);
	thread_arg.thread = thread;
	init_camera(env->camera, (float)WIN_WIDTH / (float)WIN_HEIGH);
	pthread_mutex_init(&thread_arg.mutex, NULL);
	while (++i < NUMBER_OF_THREADS)
		(pthread_create(&thread[i], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	(pthread_create(&thread[NUMBER_OF_THREADS], NULL, wait_fnc,
										&thread_arg) != 0) ? exit(3) : 0;
	clean_arg.wait_thread = thread[NUMBER_OF_THREADS];
	mlx_loop(img->mlx);
}
