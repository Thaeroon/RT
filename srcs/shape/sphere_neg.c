/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_neg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:51:58 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/26 15:52:05 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static void	get_sphere_u_v(const t_vector *p, float *u, float *v)
{
	float	phi;
	float	theta;

	phi = atan2(p->z, p->x);
	theta = asin(p->y);
	*u = 1 - (phi + M_PI) / (2 * M_PI);
	*v = (theta + M_PI / 2) / (M_PI);
}

static int	get_values(t_object *object, const t_ray *ray, t_hit_rec *rec,
																	float tmp)
{
	rec->t = tmp;
	point_at(ray, tmp, &rec->p);
	rec->normal.x = (rec->p.x) / object->radius;
	rec->normal.y = (rec->p.y) / object->radius;
	rec->normal.z = (rec->p.z) / object->radius;
	get_sphere_u_v(&rec->normal, &rec->u, &rec->v);
	return (1);
}

int			sphere_neg_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	float		tmp;

	a = dot(&ray->dir, &ray->dir);
	b = dot(&ray->ori, &ray->dir);
	c = dot(&ray->ori, &ray->ori) - (object->size * object->size);
	tmp = b * b - a * c;
	if (tmp > 0)
	{
		tmp = (-b - sqrt(b * b - a * c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
		tmp = (-b + sqrt(b * b - a * c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
	}
	return (0);
}
