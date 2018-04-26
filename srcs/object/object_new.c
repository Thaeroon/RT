/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:14 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 13:06:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "twl_xstdlib.h"

static void			suite(t_object *object)
{
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
	object->cut_lvl = 0;
	object->cut_axe = 0;
	object->flip_normal = 0;
	object->pos_x_coup = 0;
	object->pos_y_coup = 0;
	object->pos_z_coup = 0;
	object->size_coup = 0;
}

t_object			*object_new(void)
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
	suite(object);
	return (object);
}
