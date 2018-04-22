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

//void verif(t_object *object, t_ray r, t_hit_rec *rec)
//{

int decoupage(t_object *object, t_ray r, t_hit_rec *rec,t_var var)
{
	float axe0;
	float axe1;
	axe0 = 0;
	axe1 = 0;
	float niv_coup;
	niv_coup = -0;
	if(object->cut_axe == 'x')
	{
		axe0 = r.ori.x + var.temp0 * r.dir.x;
		axe1 = r.ori.x + var.temp1 * r.dir.x;
	}
	if(object->cut_axe == 'y')
	{
		axe0 = r.ori.y + var.temp0 * r.dir.y;
		axe1 = r.ori.y + var.temp1 * r.dir.y;
	}
	if(object->cut_axe == 'z')
	{
		axe0 = r.ori.z + var.temp0 * r.dir.z;
		axe1 = r.ori.z + var.temp1 * r.dir.z;
	}
	if(object->cut_axe == 's')
	{
		if(sphere_coup_hit(object,&r,rec,var.closest) == 1)
			return(0);
	}
	if(object->cut_axe == 'c')
	{
		if(cylindre_hit(object,&r,rec,var.closest) == 1)
			return(0);
	}

	if(object->cut_axe != 'x' && object->cut_axe != 'y' && object->cut_axe != 'z')
	{
		axe0 = 0;
		axe1 = 0;
	}

	if ((twl_strcmp(object->type, "cone") == 0) && (object->cut_axe == 'x' || object->cut_axe == 'y' || object->cut_axe == 'z'))
	{
		if((axe0 >= -object->radius && axe0 <= object->radius) || (axe1 <= object->radius && axe1 >= -object->radius))
		{
			if(var.temp1 <= 0)
				return (0);
			if(var.temp0 < var.closest && var.temp1 > 0.001)
			{
				rec->t = var.temp0;
				point_at(&r, var.temp0, &rec->p);
				rec->normal.x = 0;//(rec->p.x)/object->radius;
				rec->normal.y = -0;//(rec->p.y)/object->radius;
				rec->normal.z = 0;//(rec->p.z)/object->radius;
				return (1);
			}
		}
	}
	else
	{
		if (axe0 < niv_coup)
		{
			if(axe1 <niv_coup)
				return (0);
			else
			{
				float th = var.temp0 + (var.temp1 - var.temp0) * (axe0 + 1) / (axe0-axe1);
				if(th <= 0)
					return (0);
				if(th < var.closest && th > 0.001)
				{
					rec->t = th;
					point_at(&r, th, &rec->p);
					rec->normal.x = 0;
					rec->normal.y = -1;
					rec->normal.z = 0;
					return (1);
				}
			}
		}
		else if(axe0 >= -object->radius && axe0 <= object->radius)
		{
			if(var.temp0 <= 0)
				return (0);
			if(var.temp0 < var.closest && var.temp0 > 0.001)
			{
				rec->t = var.temp0;
				point_at(&r, var.temp0, &rec->p);
				rec->normal.x = (rec->p.x)/object->radius;
				rec->normal.y =  1;
				rec->normal.z = (rec->p.z)/object->radius;
				return (1);
			}
		}
		else if (axe0 >= object->radius)
		{
			if(axe1 >= object->radius)
				return 0;
			else
			{
				float th = var.temp0 + (var.temp1-var.temp0) * (axe0 - 1) / (axe0-axe1);
				if(th <= 0)
					return(0);
				if(th < var.closest && th > 0.001)
				{
					rec->t = th;
					point_at(&r, th, &rec->p);
					rec->normal.x = 0;
					rec->normal.y = 1;
					rec->normal.z = 0;
					return (1);
				}
			}
		}
	}
	return (0);
}
