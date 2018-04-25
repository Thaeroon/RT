/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:23:28 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/25 11:46:10 by nmuller          ###   ########.fr       */
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

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	float		tmp;

	a = dot(&ray->dir, &ray->dir);
	b = dot(&ray->ori, &ray->dir);
	c = dot(&ray->ori, &ray->ori) - (object->radius * object->radius);
	tmp = b * b - a * c;
	if (tmp > 0)
	{
		tmp = (-b - sqrt(b * b - a * c)) / a;
		if (MIN_CLOSEST < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
		tmp = (-b + sqrt(b * b - a * c)) / a;
		if (MIN_CLOSEST < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
	}
	return (0);
}

int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	t_var		var;

	a = dot(&ray->dir, &ray->dir);
	b = dot(&ray->ori, &ray->dir);
	c = dot(&ray->ori, &ray->ori) - (object->radius * object->radius);
	if (b * b - a * c < 0)
		return (0);
	var.closest = closest;
	var.t0 = (-b + sqrtf(b*b - a*c)) / a;
	var.t1 = (-b - sqrtf(b*b - a*c)) / a;
	if (var.t0 > var.t1)
	{
		a = var.t0;
		var.t0 = var.t1;
		var.t1 = a;
	}
	return (decoupage(object, *ray, rec, var));
}
