/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:33:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 12:13:30 by afertah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void		point_at(const t_ray *ray, float t, t_vector *p)
{
	p->x = ray->dir.x * t;
	p->y = ray->dir.y * t;
	p->z = ray->dir.z * t;
	p->x = p->x + ray->ori.x;
	p->y = p->y + ray->ori.y;
	p->z = p->z + ray->ori.z;
}

int			object_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	if (twl_strcmp(object->type, "sphere") == 0)
		return (sphere_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "cylindre") == 0)
		return (cylindre_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "tube") == 0)
		return (tube_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "cube") == 0)
		return (cube_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "x_rectangle") == 0)
		return (yz_rectangle_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "y_rectangle") == 0)
		return (xz_rectangle_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "z_rectangle") == 0)
		return (xy_rectangle_hit(object, ray, rec, closest));
	if (twl_strcmp(object->type, "plan") == 0)
		return (plan_y(object, ray, rec, closest));
	if (twl_strcmp(object->type, "cone") == 0)
		return (cone_hit(object, ray, rec, closest));
//	if (twl_strcmp(object->type, "cabsule") == 0)
//		return (cabsule_hit(object, ray, rec, closest));
	return (0);
}

int			hit(t_env *env, const t_ray *ray, t_hit_rec *rec)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	int				hit;
	float			closest;

	hit = 0;
	closest = FLT_MAX;
	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		if (translate(elem->data, ray, rec, closest))
		{
			hit = 1;
			closest = rec->t;
			rec->obj_ptr = elem->data;
		}
		elem = next;
	}
	return (hit);
}
