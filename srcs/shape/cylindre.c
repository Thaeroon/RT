/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:15:19 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/26 19:09:52 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	t_var		var;
	t_ray		r;

	r = *ray;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	b = (r.ori.x * r.dir.x + r.ori.z * r.dir.z);
	c = (r.ori.x * r.ori.x + r.ori.z * r.ori.z) -
					object->radius * object->radius;
	if (b * b - a * c < 0)
		return (0);
	var.closest = closest;
	var.t0 = (-b + sqrtf(b * b - a * c)) / a;
	var.t1 = (-b - sqrtf(b * b - a * c)) / a;
	if (var.t0 > var.t1)
	{
		a = var.t0;
		var.t0 = var.t1;
		var.t1 = a;
	}
	return (cut(object, r, rec, var));
}
