/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_dielectric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:37:20 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:06:41 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scatter.h"

static int		refract(const t_vector *v, t_vector *n, float niovnt,
														t_vector *refracted)
{
	t_vector		uv;
	float			dt;
	float			discr;

	uv = normalise(*v);
	dt = scal_prod(&uv, n);
	discr = 1.0 - niovnt * niovnt * (1.0 - (dt * dt));
	if (discr > 0)
	{
		refracted->x = niovnt * (uv.x - (n->x * dt)) - n->x * sqrt(discr);
		refracted->y = niovnt * (uv.y - (n->y * dt)) - n->y * sqrt(discr);
		refracted->z = niovnt * (uv.z - (n->z * dt)) - n->z * sqrt(discr);
		return (1);
	}
	else
	{
		refracted->x = 0;
		refracted->y = 0;
		refracted->z = 0;
		return (0);
	}
}

static float	schlick(float cosine, float ref_idx)
{
	float	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

static void		set_scatter(t_ray *scatter, t_hit_rec *rec, t_vector new_dir,
																	float blur)
{
	t_vector	rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();
	scatter->ori.x = rec->p.x;
	scatter->ori.y = rec->p.y;
	scatter->ori.z = rec->p.z;
	scatter->dir.x = new_dir.x + (1 - blur) * rand_unit_vect.x;
	scatter->dir.y = new_dir.y + (1 - blur) * rand_unit_vect.y;
	scatter->dir.z = new_dir.z + (1 - blur) * rand_unit_vect.z;
}

static float	set_out(t_vector *outward_normal, t_vector normal,
											float refraction_idx, int is_neg)
{
	float	niovnt;

	if (is_neg)
	{
		outward_normal->x = -normal.x;
		outward_normal->y = -normal.y;
		outward_normal->z = -normal.z;
		niovnt = refraction_idx;
	}
	else
	{
		outward_normal->x = normal.x;
		outward_normal->y = normal.y;
		outward_normal->z = normal.z;
		niovnt = 1.0 / refraction_idx;
	}
	return (niovnt);
}

int				scatter_dielectric(const t_ray *ray, t_hit_rec *rec,
															t_ray *scatter)
{
	t_vector	outward;
	float		niovnt;
	t_vector	refracted;
	float		reflect_prob;
	float		cosine;

	reflect_prob = 1.0;
	if (scal_prod(&ray->dir, &rec->normal) > 0)
	{
		niovnt = set_out(&outward, rec->normal, rec->obj_ptr->refraction, 1);
		cosine = niovnt * scal_prod(&ray->dir, &rec->normal) / norm(&ray->dir);
	}
	else
	{
		niovnt = set_out(&outward, rec->normal, rec->obj_ptr->refraction, 0);
		cosine = -scal_prod(&ray->dir, &rec->normal) / norm(&ray->dir);
	}
	if (refract(&ray->dir, &outward, niovnt, &refracted))
		reflect_prob = schlick(cosine, rec->obj_ptr->refraction);
	if (drand48() < reflect_prob)
		set_scatter(scatter, rec, reflect(ray->dir, &rec->normal),
												rec->obj_ptr->reflection);
	else
		set_scatter(scatter, rec, refracted, rec->obj_ptr->transparence);
	return (1);
}
