/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_from_dict.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:12 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 20:06:45 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "utils.h"
#include <stdlib.h>
#include "twl_dict.h"

static void			suite1(t_object *object, t_dict *dict)
{
	char	*ret_val;

	ret_val = dict_get_with_default(dict, "radius", "1");
	object->radius = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "size", "1");
	object->size = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "ambient", "0");
	object->ambient = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "diffuse", "0");
	object->diffuse = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "transparence", "0");
	object->transparence = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "reflection", "0");
	object->reflection = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "refraction", "0");
	object->refraction = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "xpm_texture_file", "");
	object->texture.file = twl_strdup(ret_val);
	ret_val = dict_get_with_default(dict, "texture_offset_x", "0");
	object->texture.offset_x = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "texture_offset_y", "0");
	object->texture.offset_y = twl_atof(ret_val);
}

static void			suite2(t_object *object, t_dict *dict)
{
	char	*ret_val;

	ret_val = dict_get_with_default(dict, "texture_stretch_x", "1");
	object->texture.stretch_x = (twl_atof(ret_val) == 0) ? 1 :
															twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "texture_stretch_y", "1");
	object->texture.stretch_y = (twl_atof(ret_val) == 0) ? 1 :
															twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "flip_normal", "0");
	object->flip_normal = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "cut_lvl", "0");
	object->cut_lvl = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "cut_axe", "0");
	object->cut_axe = *ret_val;
	ret_val = dict_get_with_default(dict, "size_coup", "0");
	object->size_coup = *ret_val;
}

void				build_object_from_dict(t_object *object, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "type", "0");
	object->type = twl_strdup(ret_val);
	ret_val = dict_get_with_default(dict, "red", "0");
	object->red = twl_atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "green", "0");
	object->green = twl_atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "blue", "0");
	object->blue = twl_atoi(ret_val) / 255.0;
	ret_val = dict_get_with_default(dict, "pos.x", "0");
	object->pos.x = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.y", "0");
	object->pos.y = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.z", "0");
	object->pos.z = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "rot_x", "0");
	object->rot_x = twl_atof(ret_val) * M_PI / 180.0;
	ret_val = dict_get_with_default(dict, "rot_y", "0");
	object->rot_y = twl_atof(ret_val) * M_PI / 180.0;
	ret_val = dict_get_with_default(dict, "rot_z", "0");
	object->rot_z = twl_atof(ret_val) * M_PI / 180.0;
	suite1(object, dict);
	suite2(object, dict);
}
