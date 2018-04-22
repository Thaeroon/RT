/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:23:28 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 16:38:40 by afertah          ###   ########.fr       */
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

	a = scal_prod(&ray->dir, &ray->dir);
	b = scal_prod(&ray->ori, &ray->dir);
	c = scal_prod(&ray->ori, &ray->ori) - (object->radius * object->radius);
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

int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	t_var		var;

	a = scal_prod(&ray->dir, &ray->dir);
	b = scal_prod(&ray->ori, &ray->dir);
	c = scal_prod(&ray->ori, &ray->ori) - (object->radius * object->radius);
	if (b * b - a * c < 0)
		return (0);
	var.closest = closest;
	var.temp0 = (-b + sqrtf(b*b - a*c)) / a;
	var.temp1 = (-b - sqrtf(b*b - a*c)) / a;
	if (var.temp0 > var.temp1)
	{
		a = var.temp0;
		var.temp0 = var.temp1;
		var.temp1 = a;
	}
	return (decoupage(object, *ray, rec, var));
}
