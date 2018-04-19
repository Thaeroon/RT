/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:17:33 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:19:02 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int			rotation_x(t_object *object, const t_ray *ray,
												t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_x);
	cos_theta = cos(object->rot_x);
	rotated_r.ori.x = ray->ori.x;
	rotated_r.ori.y = cos_theta * ray->ori.y + sin_theta * ray->ori.z;
	rotated_r.ori.z = -sin_theta * ray->ori.y + cos_theta * ray->ori.z;
	rotated_r.dir.x = ray->dir.x;
	rotated_r.dir.y = cos_theta * ray->dir.y + sin_theta * ray->dir.z;
	rotated_r.dir.z = -sin_theta * ray->dir.y + cos_theta * ray->dir.z;
	if (rotation_y(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.y = cos_theta * p.y - sin_theta * p.z;
		rec->p.z = sin_theta * p.y + cos_theta * p.z;
		rec->normal.y = cos_theta * normal.y - sin_theta * normal.z;
		rec->normal.z = sin_theta * normal.y + cos_theta * normal.z;
		return (1);
	}
	return (0);
}

int			rotation_y(t_object *object, const t_ray *ray,
												t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_y);
	cos_theta = cos(object->rot_y);
	rotated_r.ori.x = cos_theta * ray->ori.x - sin_theta * ray->ori.z;
	rotated_r.ori.y = ray->ori.y;
	rotated_r.ori.z = sin_theta * ray->ori.x + cos_theta * ray->ori.z;
	rotated_r.dir.x = cos_theta * ray->dir.x - sin_theta * ray->dir.z;
	rotated_r.dir.y = ray->dir.y;
	rotated_r.dir.z = sin_theta * ray->dir.x + cos_theta * ray->dir.z;
	if (rotation_z(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.x = cos_theta * p.x + sin_theta * p.z;
		rec->p.z = -sin_theta * p.x + cos_theta * p.z;
		rec->normal.x = cos_theta * normal.x + sin_theta * normal.z;
		rec->normal.z = -sin_theta * normal.x + cos_theta * normal.z;
		return (1);
	}
	return (0);
}

int			rotation_z(t_object *object, const t_ray *ray,
												t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_z);
	cos_theta = cos(object->rot_z);
	rotated_r.ori.x = cos_theta * ray->ori.x + sin_theta * ray->ori.y;
	rotated_r.ori.y = -sin_theta * ray->ori.x + cos_theta * ray->ori.y;
	rotated_r.ori.z = ray->ori.z;
	rotated_r.dir.x = cos_theta * ray->dir.x + sin_theta * ray->dir.y;
	rotated_r.dir.y = -sin_theta * ray->dir.x + cos_theta * ray->dir.y;
	rotated_r.dir.z = ray->dir.z;
	if (object_hit(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.x = cos_theta * p.x - sin_theta * p.y;
		rec->p.y = sin_theta * p.x + cos_theta * p.y;
		rec->normal.x = cos_theta * normal.x - sin_theta * normal.y;
		rec->normal.y = sin_theta * normal.x + cos_theta * normal.y;
		return (1);
	}
	return (0);
}
