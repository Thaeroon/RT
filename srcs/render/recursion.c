/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:06:34 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 17:08:42 by nmuller          ###   ########.fr       */
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

t_vector		get_color(t_env *env, const t_ray *prim_ray, int depth)
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
