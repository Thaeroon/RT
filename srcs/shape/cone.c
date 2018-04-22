
#include "shape.h"

int			cone_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest)
{
	float	a;
	float	b;
	float	c;
	float	temp1;
	float	temp0;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z - ray->dir.y
													* ray->dir.y;
	b = 2 * ray->ori.x * ray->dir.x + 2 * ray->ori.z * ray->dir.z - 2
													* ray->ori.y * ray->dir.y;
	c = (ray->ori.x * ray->ori.x + ray->ori.z * ray->ori.z - ray->ori.y
													* ray->ori.y);
	temp0 = (-b + sqrtf(b * b - 4 * a * c)) / (2 * a);
	temp1 = (-b - sqrtf(b * b - 4 * a * c)) / (2 * a);
	if (temp0 > temp1)
	{
		a = temp0;
		temp0 = temp1;
		temp1 = a;
	}
	return (decoupage(object, *ray, rec, closest, temp0, temp1, 'y'));
}
