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
	float	x;
	float	z;
	float	coord[4];
	t_var	var;

	var.t0 = (-ray->ori.y) / ray->dir.y;
	if (var.t0 < MIN_CLOSEST || var.t0 > closest)
		return (0);
	var.closest = closest;
	var.t1 = 0;
	x = ray->ori.x + var.t0 * ray->dir.x;
	z = ray->ori.z + var.t0 * ray->dir.z;
	coord[0] = -object->size;
	coord[1] = object->size;
	coord[2] = -object->size;
	coord[3] = object->size;
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = var.t0;
	point_at(ray, var.t0, &rec->p);
	rec->normal = (object->flip_normal > 0) ? new_vector(0, -1, 0)
														: new_vector(0, 1, 0);
	return (decoupage(object, *ray, rec, var));
}
