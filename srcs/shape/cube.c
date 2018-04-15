#include "shape.h"

int            cube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_object        tmp_obj;
	float           save_closest;
	t_ray			tmp_ray;

	save_closest = closest;
	tmp_obj = *object;
	tmp_ray = *ray;
	tmp_obj.flip_normal = 0;
	tmp_ray.ori.z = tmp_ray.ori.z - tmp_obj.size;
	if (xy_rectangle_hit(&tmp_obj, &tmp_ray, rec, closest))
	{
		closest = rec->t;
		rec->p.z = rec->p.z + tmp_obj.size;
	}
	tmp_ray.ori.z = ray->ori.z;
	tmp_ray.ori.y = tmp_ray.ori.y - tmp_obj.size;
	if (xz_rectangle_hit(&tmp_obj, &tmp_ray, rec ,closest))
	{
		closest = rec->t;
		rec->p.y = rec->p.y + tmp_obj.size;
	}
	tmp_ray.ori.y = ray->ori.y;
	tmp_ray.ori.x = tmp_ray.ori.x - tmp_obj.size;
	if (yz_rectangle_hit(&tmp_obj, &tmp_ray, rec ,closest))
	{
		closest = rec->t;
		rec->p.x = rec->p.x + tmp_obj.size;
	}
	tmp_obj.flip_normal = 1;
	tmp_ray.ori.x = ray->ori.x;
	tmp_ray.ori.z = tmp_ray.ori.z + tmp_obj.size;
	if (xy_rectangle_hit(&tmp_obj, &tmp_ray, rec ,closest))
	{
		closest = rec->t;
		rec->p.z = rec->p.z - tmp_obj.size;
	}
	tmp_ray.ori.z = ray->ori.z;
	tmp_ray.ori.y = tmp_ray.ori.y + tmp_obj.size;
	if (xz_rectangle_hit(&tmp_obj, &tmp_ray, rec ,closest))
	{
		closest = rec->t;
		rec->p.y = rec->p.y - tmp_obj.size;
	}
	tmp_ray.ori.y = ray->ori.y;
	tmp_ray.ori.x = tmp_ray.ori.x + tmp_obj.size;
	if (yz_rectangle_hit(&tmp_obj, &tmp_ray, rec ,closest))
	{
		closest = rec->t;
		rec->p.x = rec->p.x - tmp_obj.size;
	}
	return (closest != save_closest);
}