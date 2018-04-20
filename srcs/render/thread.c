/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:35:15 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:43:43 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "texture.h"

static t_vector	background_color(t_camera *camera, const t_ray *prim_ray)
{
	t_vector	color;
	float		t;

	if (camera->sky_background)
	{
		t = 0.5 * (normalise(prim_ray->dir).y + 1.0);
		color.x = (1.0 - t) + t * 0.5;
		color.y = (1.0 - t) + t * 0.7;
		color.z = (1.0 - t) + t * 1.0;
	}
	else
		color = new_vector(camera->min_illumination, camera->min_illumination,
													camera->min_illumination);
	return (color);
}

static t_vector	get_color(t_env *env, const t_ray *prim_ray, int depth)
{
	t_hit_rec		rec;
	t_ray			sec_ray;
	t_vector		emited;

	if (hit(env, prim_ray, &rec))
	{
		if (rec.obj_ptr->diffuse > 0)
		{
			emited.x = rec.obj_ptr->diffuse * rec.obj_ptr->red;
			emited.y = rec.obj_ptr->diffuse * rec.obj_ptr->green;
			emited.z = rec.obj_ptr->diffuse * rec.obj_ptr->blue;
		}
		else
			emited = new_vector(MIN_EMITED, MIN_EMITED, MIN_EMITED);
		if (depth < RAY_DEPTH && scatter(prim_ray, &rec, &sec_ray))
			return (get_texture(&rec, get_color(env, &sec_ray, depth + 1)));
		else
			return (emited);
	}
	else
		return (background_color(env->camera, prim_ray));
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

void			for_each_pixel(t_thread_arg *thread_arg, t_ray *ray,
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
			pthread_cond_signal(&thread_arg->progress);
	}
}
