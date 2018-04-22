/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:35:15 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 11:27:26 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		apply_gamma(t_vector *col)
{
	col->x = sqrt(col->x);
	col->y = sqrt(col->y);
	col->z = sqrt(col->z);
	col->x = (col->x > 1) ? 1 : col->x;
	col->y = (col->y > 1) ? 1 : col->y;
	col->z = (col->z > 1) ? 1 : col->z;
}

static void		get_ray(t_ray *ray, t_camera *cam, int i, int j)
{
	float	u;
	float	v;

	u = (float)(i + drand48()) / (float)WIN_WIDTH;
	v = (float)(j + drand48()) / (float)WIN_HEIGH;
	ray->dir.x = cam->up_left.x + u * cam->hori.x - v
										* cam->vert.x - cam->pos.x;
	ray->dir.y = cam->up_left.y + u * cam->hori.y - v
										* cam->vert.y - cam->pos.y;
	ray->dir.z = cam->up_left.z + u * cam->hori.z - v
										* cam->vert.z - cam->pos.z;
}

static t_vector	apply_aa(t_thread_arg *thread_arg, t_ray *ray, int x, int y)
{
	int			k;
	t_vector	col;

	k = -1;
	set_value_vector(&col, 0, 0, 0);
	while (++k < AA_STRENGH)
	{
		get_ray(ray, thread_arg->env->camera, x, y);
		col = add_vector(col, get_color(thread_arg->env, ray, 0));
	}
	col.x = col.x / (float)AA_STRENGH;
	col.y = col.y / (float)AA_STRENGH;
	col.z = col.z / (float)AA_STRENGH;
	return (col);
}

static void		for_each_pixel(t_thread_arg *thread_arg, t_ray *ray,
										int pix_per_thread, int thread_num)
{
	int			i;
	int			x;
	int			y;
	t_vector	col;

	i = -1;
	x = (thread_num * pix_per_thread) % WIN_WIDTH;
	y = (thread_num * pix_per_thread) / WIN_WIDTH;
	x--;
	while (++i < pix_per_thread)
	{
		(thread_arg->end) ? pthread_exit(NULL) : 0;
		if (++x >= WIN_WIDTH)
		{
			x = 0;
			y++;
		}
		col = apply_aa(thread_arg, ray, x, y);
		apply_gamma(&col);
		apply_filter(thread_arg->env->camera, &col);
		put_pixel(thread_arg->img->buffer, x, y, &col);
		if ((thread_num * pix_per_thread + i)
								% (WIN_HEIGH * WIN_WIDTH / LOADING_STEP) == 0)
			loading(thread_arg->img->loading_img_buffer, 0);
	}
}

void			*thread_fnc(void *data)
{
	t_thread_arg	*thread_arg;
	t_ray			ray;
	int				pix_per_thread;
	int				thread_num;

	thread_arg = (t_thread_arg*)data;
	pthread_mutex_lock(&thread_arg->mutex);
	thread_num = thread_arg->thread_num;
	thread_arg->thread_num += 1;
	ray = *thread_arg->ray;
	pthread_mutex_unlock(&thread_arg->mutex);
	pix_per_thread = WIN_HEIGH * WIN_WIDTH / NUMBER_OF_THREADS;
	for_each_pixel(thread_arg, &ray, pix_per_thread, thread_num);
	pthread_exit(NULL);
}
