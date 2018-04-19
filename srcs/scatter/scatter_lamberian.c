/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_lamberian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:37:23 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:40:25 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scatter.h"

int			scatter_lamberian(t_hit_rec *rec, t_ray *scatter)
{
	t_vector		target;
	t_vector		rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();
	scatter->ori.x = rec->p.x;
	scatter->ori.y = rec->p.y;
	scatter->ori.z = rec->p.z;
	target.x = scatter->ori.x + rec->normal.x + rand_unit_vect.x;
	target.y = scatter->ori.y + rec->normal.y + rand_unit_vect.y;
	target.z = scatter->ori.z + rec->normal.z + rand_unit_vect.z;
	scatter->dir.x = target.x - rec->p.x;
	scatter->dir.y = target.y - rec->p.y;
	scatter->dir.z = target.z - rec->p.z;
	return (1);
}
