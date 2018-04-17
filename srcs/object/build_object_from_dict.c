#include "object.h"
#include "utils.h"
#include <stdlib.h>
#include "twl_dict.h"

void				build_object_from_dict(t_object *object, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "type", "0");
	object->type = twl_strdup(ret_val);
	ret_val = dict_get_with_default(dict, "red", "0");
	object->red = atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "green", "0");
	object->green = atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "blue", "0");
	object->blue = atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "pos.x", "0");
	object->pos.x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.y", "0");
	object->pos.y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.z", "0");
	object->pos.z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "rot_x", "0");
	object->rot_x = atof(ret_val) * M_PI / 180.0;
	ret_val = dict_get_with_default(dict, "rot_y", "0");
	object->rot_y = atof(ret_val) * M_PI / 180.0;
	ret_val = dict_get_with_default(dict, "rot_z", "0");
	object->rot_z = atof(ret_val) * M_PI / 180.0;
	ret_val = dict_get_with_default(dict, "radius", "1");
	object->radius = atof(ret_val);
	ret_val = dict_get_with_default(dict, "size", "1");
	object->size = atof(ret_val);
	ret_val = dict_get_with_default(dict, "ambient", "0");
	object->ambient = atof(ret_val);
	ret_val = dict_get_with_default(dict, "diffuse", "0");
	object->diffuse = atof(ret_val);
	ret_val = dict_get_with_default(dict, "transparence", "0");
	object->transparence = atof(ret_val);
	ret_val = dict_get_with_default(dict, "reflection", "0");
	object->reflection = atof(ret_val);
	ret_val = dict_get_with_default(dict, "refraction", "0");
	object->refraction = atof(ret_val);
	ret_val = dict_get_with_default(dict, "xpm_texture_file", "");
	object->texture.file = twl_strdup(ret_val);
	ret_val = dict_get_with_default(dict, "texture_offset_x", "0");
	object->texture.offset_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "texture_offset_y", "0");
	object->texture.offset_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "texture_stretch_x", "1");
	object->texture.stretch_x = (atof(ret_val) == 0) ? 1 : atof(ret_val);
	ret_val = dict_get_with_default(dict, "texture_stretch_y", "1");
	object->texture.stretch_y = (atof(ret_val) == 0) ? 1 : atof(ret_val);
	ret_val = dict_get_with_default(dict, "flip_normal", "0");
	object->flip_normal = atof(ret_val);
}
