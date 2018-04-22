/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:12:57 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 16:20:47 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static int	getval(float *ori1, float *ori2, float size, float r_ori)
{
	*ori1 = r_ori;
	*ori2 = *ori2 + size;
	return (1);
}

static int	init(t_object *tmp_object, t_object *object, t_ray *tmp_ray,
															const t_ray *ray)
{
	*tmp_object = *object;
	*tmp_ray = *ray;
	return (0);
}

int			cube_hit(t_object *object, const t_ray *r, t_hit_rec *rec,
													float closest)
{
	t_object		t_obj;
	float			save_closest;
	t_ray			t_r;

	save_closest = closest;
	t_obj.flip_normal = init(&t_obj, object, &t_r, r);
	getval(&t_r.ori.z, &t_r.ori.z, -t_obj.size, r->ori.z);
	if (xy_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.z, t_obj.size, rec->t);
	getval(&t_r.ori.z, &t_r.ori.y, -t_obj.size, r->ori.z);
	if (xz_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.y, t_obj.size, rec->t);
	getval(&t_r.ori.y, &t_r.ori.x, -t_obj.size, r->ori.y);
	if (yz_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.x, t_obj.size, rec->t);
	t_obj.flip_normal = getval(&t_r.ori.x, &t_r.ori.z, t_obj.size, r->ori.x);
	if (xy_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.z, -t_obj.size, rec->t);
	getval(&t_r.ori.z, &t_r.ori.y, t_obj.size, r->ori.z);
	if (xz_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.y, -t_obj.size, rec->t);
	getval(&t_r.ori.y, &t_r.ori.x, t_obj.size, r->ori.y);
	if (yz_rectangle_hit(&t_obj, &t_r, rec, closest))
		getval(&closest, &rec->p.x, -t_obj.size, rec->t);
	return (closest != save_closest);
}
