/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homothetie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:16:29 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:16:56 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		homothetie(t_object *object, const t_ray *ray,
												t_hit_rec *rec, float closest)
{
	t_ray	modif_r;
	float	factor;

	factor = object->reflection;
	modif_r.ori.x = ray->ori.x / factor;
	modif_r.ori.y = ray->ori.y / factor;
	modif_r.ori.z = ray->ori.x / factor;
	modif_r.dir.x = ray->dir.x / factor;
	modif_r.dir.y = ray->dir.y / factor;
	modif_r.dir.z = ray->dir.z / factor;
	if (object_hit(object, &modif_r, rec, closest))
	{
		rec->p.x *= factor;
		rec->p.y *= factor;
		rec->p.z *= factor;
		rec->normal.x *= factor;
		rec->normal.y *= factor;
		rec->normal.z *= factor;
		return (1);
	}
	return (0);
}
