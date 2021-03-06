/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:37:27 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 22:53:25 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scatter.h"

t_vector	reflect(t_vector dir, t_vector *normal)
{
	t_vector	ret;
	float		d;

	d = dot(&dir, normal);
	ret.x = dir.x - 2 * d * normal->x;
	ret.y = dir.y - 2 * d * normal->y;
	ret.z = dir.z - 2 * d * normal->z;
	return (ret);
}

t_vector	random_in_unit_sphere(void)
{
	t_vector	p;

	set_value_vector(&p, 2.0 * drand48() - 1, 2.0 * drand48() - 1,
														2.0 * drand48() - 1);
	while (dot(&p, &p) >= 1.0)
	{
		set_value_vector(&p, 2.0 * drand48() - 1, 2.0 * drand48() - 1,
														2.0 * drand48() - 1);
	}
	return (p);
}

int			scatter(const t_ray *ray, t_hit_rec *rec, t_ray *scatter)
{
	if (rec->obj_ptr->diffuse > 0)
		return (false);
	if (rec->obj_ptr->refraction > 0)
		return (scatter_dielectric(ray, rec, scatter));
	if (rec->obj_ptr->reflection > 0)
		return (scatter_metal(ray, rec, scatter));
	return (scatter_lamberian(rec, scatter));
}
