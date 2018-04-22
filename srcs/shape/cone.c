#include "shape.h"
int cone_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector oc;
	float a;
	float b;
	float c;
	float temp1;
	float temp0;
	float discrim;
	t_ray r;
	r = *ray;
	oc.x = r.ori.x;
	oc.y = r.ori.y;
	oc.z = r.ori.z;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z - r.dir.y * r.dir.y;
	b = 2*oc.x * r.dir.x + 2*oc.z * r.dir.z - 2*oc.y * r.dir.y;
	c = (oc.x * oc.x + oc.z * oc.z - oc.y * oc.y);
	discrim = 4*b*b - a*c;
	temp0 = (-b + sqrtf(b*b - 4*a*c)) / (2*a);
	temp1 = (-b - sqrtf(b*b - 4*a*c)) / (2*a);
	if(temp0 > temp1)
	{
		float tmp = temp0;
		temp0 = temp1;
		temp1 = tmp;
	}
	return (decoupage(object,r,rec,closest,temp0,temp1,'s'));
}
