/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:15:38 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/26 17:15:42 by pbeller          ###   ########.fr       */
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

static void		get_tube_u_v(const t_vector *p, float *u, float *v)
{
	float	phi;
	float	theta;

	phi = atan2(p->z, p->x);
	theta = asin(p->y);
	*u = 1 - (phi + M_PI) / (2 * M_PI);
	*v = (theta + M_PI / 2) / (M_PI);
}

int				cylindre_neg_hit(t_object *object, const t_ray *ray,
												t_hit_rec *rec, float closest)
{
	float		a;
	float		b;
	float		c;
	float		temp0;
	float		temp1;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = (ray->ori.x * ray->dir.x + ray->ori.z * ray->dir.z);
	c = (ray->ori.x * ray->ori.x + ray->ori.z * ray->ori.z) -
									object->size * object->size;
	temp0 = (-b + sqrtf(b * b - a * c)) / (a);
	temp1 = (-b - sqrtf(b * b - a * c)) / (a);
	(temp0 > temp1) ? ft_swap_tmp(&temp0, &temp1) : 0;
	if (temp0 < closest && temp0 > 0.001)
	{
		rec->t = temp0;
		point_at(ray, temp0, &rec->p);
		rec->normal.x = (rec->p.x) / object->radius;
		rec->normal.y = 0;
		rec->normal.z = (rec->p.z) / object->radius;
		get_tube_u_v(&rec->p, &rec->u, &rec->v);
		return (1);
	}
	return (0);
}
