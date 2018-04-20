/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:19:01 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:14:35 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		plan_y(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float	t;
	float	x;
	float	z;
	float	coord[4];

	t = (-ray->ori.y) / ray->dir.y;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	x = ray->ori.x + t * ray->dir.x;
	z = ray->ori.z + t * ray->dir.z;
	coord[0] = -object->size;
	coord[1] = object->size;
	coord[2] = -object->size;
	coord[3] = object->size;
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->flip_normal > 0) ? new_vector(0, -1, 0)
														: new_vector(0, 1, 0);
	return (1);
}