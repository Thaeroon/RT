
#include "shape.h"

int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float		a;
	float		b;
	float		c;
	t_var		var;

	a = dot(&ray->dir, &ray->dir);
	b = dot(&ray->ori, &ray->dir);
	c = dot(&ray->ori, &ray->ori) - (1*1);
	if (b * b - a * c < 0)
		return (0);
	var.closest = closest;
	var.t0 = (-b + sqrtf(b * b - a * c)) / a;
	var.t1 = (-b - sqrtf(b * b - a *c )) / a;
	if (var.t1 > var.t0)
	{
		a = var.t0;
		var.t0 = var.t1;
		var.t1 = a;
	}
	rec->normal.x = (rec->p.x) / object->radius;
	rec->normal.y = (rec->p.y) / object->radius;
	rec->normal.z = (rec->p.z) / object->radius;
	return (decoupage(object, *ray, rec, var));
}
