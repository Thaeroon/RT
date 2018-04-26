#include "shape.h"

void	swap_var(t_var *var)
{
	float	a;

	if (var->t1 < var->t0)
	{
		a = var->t0;
		var->t0 = var->t1;
		var->t1 = a;
	}
	if (var->t0 < MIN_CLOSEST)
	{
		a = var->t0;
		var->t0 = var->t1;
		var->t1 = a;
	}
}

int		cone_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	float	a;
	float	b;
	float	c;
	t_var	var;
	t_ray	r;

	r = *ray;
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z - ray->dir.y
		* ray->dir.y;
	b = 2 * ray->ori.x * ray->dir.x + 2 * ray->ori.z * ray->dir.z - 2
		* ray->ori.y * ray->dir.y;
	c = (ray->ori.x * ray->ori.x + ray->ori.z * ray->ori.z - ray->ori.y
			* ray->ori.y);
	var.t0 = (-b - sqrtf(b * b - 4 * a * c)) / (2 * a);
	var.t1 = (-b + sqrtf(b * b - 4 * a * c)) / (2 * a);
	var.closest = closest;
	swap_var(&var);
	rec->normal = cross(cross(rec->p, new_vector(0, 1, 0)), rec->p);
	rec->normal = normalise(rec->normal);
	if (dot(&rec->normal, &ray->dir) > 0)
		rec->normal = mult_vect_float(rec->normal, -1);
	return (decoupage(object, r, rec, var));
}
