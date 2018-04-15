#include "object.h"
#include <stdio.h>

void				object_print(t_object *object)
{
	printf("===== Print Object =====\n");
	printf("type: %s\n", object->type);
	printf("red: %f\n", object->red);
	printf("green: %f\n", object->green);
	printf("blue: %f\n", object->blue);
	printf("pos.x: %f\n", object->pos.x);
	printf("pos.y: %f\n", object->pos.y);
	printf("pos.z: %f\n", object->pos.z);
	printf("rot_x: %f\n", object->rot_x);
	printf("rot_y: %f\n", object->rot_y);
	printf("rot_z: %f\n", object->rot_z);
	printf("radius: %f\n", object->radius);
	printf("size: %f\n", object->size);
	printf("ambient: %f\n", object->ambient);
	printf("diffuse: %f\n", object->diffuse);
	printf("transparence: %f\n", object->transparence);
	printf("reflection: %f\n", object->reflection);
	printf("refraction: %f\n", object->refraction);
	printf("xpm_texture_file: %s\n", object->texture.file);
	printf("flip_normal: %d\n", object->flip_normal);
}
