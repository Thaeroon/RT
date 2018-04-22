#include "shape.h"

int		tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		temp0;
	float		temp1;
	t_ray		r;

	r = *ray;
	oc.x = r.ori.x;
	oc.y = 0;
	oc.z = r.ori.z;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	b = (oc.x * r.dir.x + oc.z * r.dir.z);
	c = (oc.x * oc.x + oc.y * oc.y + oc.z * oc.z) - object->radius * object->radius;
	temp0 = (-b + sqrtf(b*b - a*c)) / (a);
	temp1 = (-b - sqrtf(b*b - a*c)) / (a);
	if(temp0 > temp1)
	{
		float tmp = temp0;
		temp0 = temp1;
		temp1 = tmp;
	}
	if(temp0 < closest && temp0 > 0.001)
	{
		rec->t = temp0;
		point_at(&r, temp0, &rec->p);
		rec->normal.x = (rec->p.x)/object->radius;
		rec->normal.y =  0;
		rec->normal.z = (rec->p.z)/object->radius;
		return (1);
	}
	return (0);
}
