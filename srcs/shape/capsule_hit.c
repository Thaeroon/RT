#include "shape.h"
t_ray homothetie_sphere(t_ray *ray,float scx, float scy, float scz)
{
	t_ray r;
	r.ori.x = ray->ori.x * scx;
	r.ori.y = ray->ori.y * scy;
	r.ori.z = ray->ori.x * scz;
	r.dir.x = ray->dir.x * scx;
	r.dir.y = ray->dir.y * scy;
	r.dir.z = ray->dir.z * scz;
	return (r);
}

int		capsule_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray r;
	r = *ray;

//	r = homothetie_sphere(&r,2,1,1);
	if(sphere_hit(object,ray,rec,closest))
		return(1);
	return 0;
}
