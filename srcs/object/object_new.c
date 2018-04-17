#include "object.h"
#include "twl_xstdlib.h"

t_object			*object_new()
{
	t_object		*object;

	object = twl_malloc_x0(sizeof(t_object));
	object->red = 0;
	object->green = 0;
	object->blue = 0;
	object->pos.x = 0.0;
	object->pos.y = 0.0;
	object->pos.z = 0.0;
	object->rot_x = 0.0;
	object->rot_y = 0.0;
	object->rot_z = 0.0;
	object->radius = 0.0;
	object->size = 0.0;
	object->ambient = 0.0;
	object->diffuse = 0.0;
	object->transparence = 1.0;
	object->reflection = 0.0;
	object->refraction = 0.0;
	object->texture.ptr = 0;
	object->texture.file = 0;
	object->texture.buffer = 0;
	object->texture.width = 0;
	object->texture.height = 0;
	object->texture.line_s = 0;
	object->texture.bpp = 0;
	object->texture.offset_x = 0.0;
	object->texture.offset_y = 0.0;
	object->texture.stretch_x = 1.0;
	object->texture.stretch_y = 1.0;
	object->texture.endian = 0;
	object->flip_normal = 0;
	return (object);
}
