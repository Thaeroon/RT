/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:18:51 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 17:10:48 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		verif_neg(t_object *object, t_ray r, t_hit_rec *rec, float closest)
{
	if (object->cut_axe == '1')
	{
		if (cylindre_neg_hit(object, &r, rec, closest) == 1)
			return (0);
	}
	if (object->cut_axe == '2')
	{
		if (cone_neg_hit(object, &r, rec, closest) == 1)
			return (0);
	}
	if (object->cut_axe == '3')
	{
		if (sphere_neg_hit(object, &r, rec, closest) == 1)
			return (0);
	}
	if (object->cut_axe == '4')
	{
		if (cube_neg_hit(object, &r, rec, closest) == 1)
			return (0);
	}
	return (1);
}

void	verif(t_ray r, t_object *object, t_var *var)
{
	if (object->cut_axe == 'x')
	{
		var->axe0 = r.ori.x + var->t0 * r.dir.x;
		var->axe1 = r.ori.x + var->t1 * r.dir.x;
	}
	if (object->cut_axe == 'y')
	{
		var->axe0 = r.ori.y + var->t0 * r.dir.y;
		var->axe1 = r.ori.y + var->t1 * r.dir.y;
	}
	if (object->cut_axe == 'z')
	{
		var->axe0 = r.ori.z + var->t0 * r.dir.z;
		var->axe1 = r.ori.z + var->t1 * r.dir.z;
	}
	if (object->cut_axe != 'x' && object->cut_axe != 'y' &&
	object->cut_axe != 'z')
	{
		var->axe0 = 0;
		var->axe1 = 0;
	}
}

int		cut(t_object *object, t_ray r, t_hit_rec *rec, t_var var)
{
	verif(r, object, &var);
	if (verif_neg(object, r, rec, var.closest) == 0)
		return (0);
	if ((twl_strcmp(object->type, "cone_coup") == 0) && (object->cut_axe
			== 'x' || object->cut_axe == 'y' || object->cut_axe == 'z'))
	{
		if ((var.axe0 >= -object->radius && var.axe0 <= object->cut_lvl) ||
				(var.axe1 <= object->cut_lvl && var.axe1 >= -object->radius))
		{
			if (var.t1 <= 0)
				return (0);
			if (var.t0 < var.closest && var.t1 > MIN_CLOSEST)
			{
				rec->t = var.t0;
				point_at(&r, var.t0, &rec->p);
				return (1);
			}
		}
	}
	else
		return (hit_obj(r, object, var, rec));
	return (0);
}
