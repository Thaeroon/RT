/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:35:23 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:36:26 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		xy_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float	t;
	float	x;
	float	y;
	float	coord[4];

	t = (-ray->ori.z) / ray->dir.z;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	x = ray->ori.x + t * ray->dir.x;
	y = ray->ori.y + t * ray->dir.y;
	coord[0] = -object->size;
	coord[1] = object->size;
	coord[2] = -object->size;
	coord[3] = object->size;
	if (x < coord[0] || x > coord[1] || y < coord[2] || y > coord[3])
		return (0);
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (y - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->flip_normal > 0) ? new_vector(0, 0, -1)
														: new_vector(0, 0, 1);
	return (1);
}

int		yz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float	t;
	float	z;
	float	y;
	float	coord[4];

	t = (-ray->ori.x) / ray->dir.x;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	z = ray->ori.z + t * ray->dir.z;
	y = ray->ori.y + t * ray->dir.y;
	coord[0] = -object->size;
	coord[1] = object->size;
	coord[2] = -object->size;
	coord[3] = object->size;
	if (y < coord[0] || y > coord[1] || z < coord[2] || z > coord[3])
		return (0);
	rec->u = (y - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->flip_normal > 0) ? new_vector(-1, 0, 0)
														: new_vector(1, 0, 0);
	return (1);
}

int		xz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
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
	if (x < coord[0] || x > coord[1] || z < coord[2] || z > coord[3])
		return (0);
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->flip_normal > 0) ? new_vector(0, -1, 0)
														: new_vector(0, 1, 0);
	return (1);
}
