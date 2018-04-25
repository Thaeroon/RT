/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:18:51 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:58 by afertah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
int verif_neg(t_object *object, t_ray r, t_hit_rec *rec, float closest)
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
return(1);
}
void verif(t_ray r, t_object *object, t_var *var)
{
	if (object->cut_axe == 'x')
	{
		var->axe0 = r.ori.x + var->t0 * r.dir.x;
		var->axe1 = r.ori.x + var->t1 * r.dir.x;
	}
	if(object->cut_axe == 'y')
	{
		var->axe0 = r.ori.y + var->t0 * r.dir.y;
		var->axe1 = r.ori.y + var->t1 * r.dir.y;
	}
	if(object->cut_axe == 'z')
	{
		var->axe0 = r.ori.z + var->t0 * r.dir.z;
		var->axe1 = r.ori.z + var->t1 * r.dir.z;
	}
	if(object->cut_axe != 'x' && object->cut_axe != 'y' && 
	object->cut_axe != 'z' && object->cut_axe != 's')
	{
		var->axe0 = 0;
		var->axe1 = 0;
	}
}

int hit_top(t_ray r,t_var var, t_hit_rec *rec)
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
	return(0);
}

int hit_middle(t_ray r, t_var var, t_hit_rec *rec)
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

int hit_low(t_ray r, t_var var, t_hit_rec *rec)
{
	if (var.th <= 0)
		return(0);
	if (var.th < var.closest && var.th > 0.001)
	{
		rec->t = var.th;
		point_at(&r, var.th, &rec->p);
		rec->normal.x = 0;
		rec->normal.y = 1;
		rec->normal.z = 0;
		return (1);
	}
	return(0);
}

int hit_obj(t_ray r, t_object *object, t_var v, t_hit_rec *rec)
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

int decoupage(t_object *object, t_ray r, t_hit_rec *rec,t_var var)
{
	verif(r, object, &var);
	if(verif_neg(object, r, rec, var.closest) == 0)
		return(0);
	if ((twl_strcmp(object->type, "cone_coup") == 0) && (object->cut_axe == 'x' ||
				object->cut_axe == 'y' || object->cut_axe == 'z'))
	{
		if ((var.axe0 >= -object->radius && var.axe0 <= object->cut_lvl) || 
				(var.axe1 <= object->cut_lvl && var.axe1 >= -object->radius))
		{
			if (var.t1 <= 0)
				return (0);
			if (var.t0 < var.closest && var.t1 > 0.001)
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
