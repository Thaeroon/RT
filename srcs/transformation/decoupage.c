/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:18:51 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 12:42:57 by afertah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int decoupage(t_object *object, t_ray r, t_hit_rec *rec, float closest,float temp0,float temp1,char axe)
{
	float niv_coup;
	niv_coup = -0;
	float axe0;
	float axe1;
	axe0 = 0;
	axe1 = 0;
	if(axe == 'x')
	{
		axe0 = r.ori.x + temp0 * r.dir.x;
		axe1 = r.ori.x + temp1 * r.dir.x;
	}
	if(axe == 'y')
	{
		axe0 = r.ori.y + temp0 * r.dir.y;
		axe1 = r.ori.y + temp1 * r.dir.y;
	}
	if(axe == 'z')
	{
		axe0 = r.ori.z + temp0 * r.dir.z;
		axe1 = r.ori.z + temp1 * r.dir.z;
	}
	if(axe == 's')
	{
		if(sphere_coup_hit(object,&r,rec,closest) == 1)
			return(0);
	}

	if(axe != 'x' && axe != 'y' && axe != 'z')
	{
		axe0 = 0;
		axe1 = 0;
	}

	if ((twl_strcmp(object->type, "cone") == 0) && (axe == 'x' || axe == 'y' || axe == 'z'))
	{
		if((axe0 >= -object->radius && axe0 <= object->radius) || (axe1 <= object->radius && axe1 >= -object->radius))
		{
			if(temp1 <= 0)
				return (0);
			if(temp0 < closest && temp1 > 0.00)
			{
				rec->t = temp0;
				point_at(&r, temp0, &rec->p);
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
				float th = temp0 + (temp1 - temp0) * (axe0 + 1) / (axe0-axe1);
				if(th <= 0)
					return (0);
				if(th < closest && th > 0.001)
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
			if(temp0 <= 0)
				return (0);
			if(temp0 < closest && temp0 > 0.001)
			{
				rec->t = temp0;
				point_at(&r, temp0, &rec->p);
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
				float th = temp0 + (temp1-temp0) * (axe0 - 1) / (axe0-axe1);
				if(th <= 0)
					return(0);
				if(th < closest && th > 0.001)
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
