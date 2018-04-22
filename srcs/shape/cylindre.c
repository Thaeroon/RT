#include "shape.h"

int		cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		discrim;
	t_var		var;
	t_ray		r;

	r = *ray;
	oc.x = r.ori.x;
	oc.y = 0;
	oc.z = r.ori.z;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	b = (oc.x * r.dir.x + oc.z * r.dir.z);
	c = (oc.x * oc.x + oc.y * oc.y +  oc.z * oc.z) - object->radius * object->radius;
	discrim = b*b - a*c;
	if (discrim < 0)
		return (0);
	var.closest = closest;
	var.temp0 = (-b + sqrtf(b*b - a*c)) / a;
	var.temp1 = (-b - sqrtf(b*b - a*c)) / a;
	if(var.temp0 > var.temp1)
	{
		float tmp = var.temp0;
		var.temp0 = var.temp1;
		var.temp1 = tmp;
	}
	return (decoupage(object,r,rec,var));
}
