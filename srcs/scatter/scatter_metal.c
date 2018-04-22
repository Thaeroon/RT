/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_metal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:37:24 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 22:04:34 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scatter.h"

int			scatter_metal(const t_ray *ray, t_hit_rec *rec, t_ray *scatter)
{
	t_vector		reflected;
	t_vector		rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();
	reflected = reflect(normalise(ray->dir), &rec->normal);
	scatter->ori.x = rec->p.x;
	scatter->ori.y = rec->p.y;
	scatter->ori.z = rec->p.z;
	scatter->dir.x = reflected.x + (1 - rec->obj_ptr->reflection)
															* rand_unit_vect.x;
	scatter->dir.y = reflected.y + (1 - rec->obj_ptr->reflection)
															* rand_unit_vect.y;
	scatter->dir.z = reflected.z + (1 - rec->obj_ptr->reflection)
															* rand_unit_vect.z;
	return (dot(&scatter->dir, &rec->normal) > 0);
}
