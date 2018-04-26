/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:08:59 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 19:13:51 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int		hit_top(t_ray r, t_var var, t_hit_rec *rec)
{
	if (var.th <= 0)
		return (0);
	if (var.th < var.closest && var.th > 0.001)
	{
		rec->t = var.th;
		point_at(&r, var.th, &rec->p);
		rec->normal.x = 0;
		rec->normal.y = -1;
		rec->normal.z = 0;
		return (1);
	}
	return (0);
}

int		hit_middle(t_ray r, t_var var, t_hit_rec *rec)
{
	if (var.t0 <= 0)
		return (0);
	if (var.t0 < var.closest && var.t0 > 0.001)
	{
		rec->t = var.t0;
		point_at(&r, var.t0, &rec->p);
		rec->normal.x = rec->p.x;
		rec->normal.y = 1;
		rec->normal.z = rec->p.z;
		return (1);
	}
	return (0);
}

int		hit_low(t_ray r, t_var var, t_hit_rec *rec)
{
	if (var.th <= 0)
		return (0);
	if (var.th < var.closest && var.th > 0.001)
	{
		rec->t = var.th;
		point_at(&r, var.th, &rec->p);
		rec->normal.x = 0;
		rec->normal.y = 1;
		rec->normal.z = 0;
		return (1);
	}
	return (0);
}

int		hit_obj(t_ray r, t_object *object, t_var v, t_hit_rec *rec)
{
	if (v.axe0 < object->cut_lvl)
	{
		if (v.axe1 < object->cut_lvl)
			return (0);
		else
		{
			v.th = v.t0 + (v.t1 - v.t0) * (v.axe0 + 1) / (v.axe0 - v.axe1);
			return (hit_top(r, v, rec));
		}
	}
	else if (v.axe0 >= -object->radius && v.axe0 <= object->radius)
		return (hit_middle(r, v, rec));
	else if (v.axe0 >= object->radius)
	{
		if (v.axe1 >= object->radius)
			return (0);
		else
		{
			v.th = v.t0 + (v.t1 - v.t0) * (v.axe0 - 1) / (v.axe0 - v.axe1);
			return (hit_low(r, v, rec));
		}
	}
	return (0);
}
