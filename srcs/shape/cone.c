/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:50:19 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/26 15:50:25 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void		swap_temp(float *temp0, float *temp1, t_object *object)
{
	float a;

	if (*temp1 < *temp0)
	{
		a = *temp0;
		*temp0 = *temp1;
		*temp1 = a;
	}
	if (*temp0 < MIN_CLOSEST)
	{
		a = *temp0;
		*temp0 = *temp1;
		*temp1 = a;
	}
	(void)object;
}

int			cone_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float	a;
	float	b;
	float	c;
	t_var	var;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z - ray->dir.y
													* ray->dir.y;
	b = 2 * ray->ori.x * ray->dir.x + 2 * ray->ori.z * ray->dir.z - 2
													* ray->ori.y * ray->dir.y;
	c = (ray->ori.x * ray->ori.x + ray->ori.z * ray->ori.z - ray->ori.y
													* ray->ori.y);
	var.t0 = (-b - sqrtf(b * b - 4 * a * c)) / (2 * a);
	var.t1 = (-b + sqrtf(b * b - 4 * a * c)) / (2 * a);
	swap_temp(&var.t0, &var.t1, object);
	if (var.t0 < closest && var.t0 > MIN_CLOSEST)
	{
		rec->t = var.t0;
		point_at(ray, var.t0, &rec->p);
		rec->normal = cross(cross(rec->p, new_vector(0, 1, 0)), rec->p);
		rec->normal = normalise(rec->normal);
		if (dot(&rec->normal, &ray->dir) > 0)
			rec->normal = mult_vect_float(rec->normal, -1);
		return (1);
	}
	return (0);
}
