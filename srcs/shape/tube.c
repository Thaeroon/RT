/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:30:15 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/22 16:30:16 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void			ft_swap_tmp(float *temp1, float *temp2)
{
	float		temp;

	temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}

int				tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
															float closest)
{
	float		a;
	float		b;
	float		c;
	float		temp0;
	float		temp1;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = (ray->ori.x * ray->dir.x + ray->ori.z * ray->dir.z);
	c = (ray->ori.x * ray->ori.x + ray->ori.z * ray->ori.z) -
									object->radius * object->radius;
	temp0 = (-b + sqrtf(b * b - a * c)) / (a);
	temp1 = (-b - sqrtf(b * b - a * c)) / (a);
	if (temp0 > temp1)
		ft_swap_tmp(&temp0, &temp1);
	if (temp0 < closest && temp0 > 0.001)
	{
		rec->t = temp0;
		point_at(ray, temp0, &rec->p);
		rec->normal.x = (rec->p.x) / object->radius;
		rec->normal.y = 0;
		rec->normal.z = (rec->p.z) / object->radius;
		return (1);
	}
	return (0);
}
