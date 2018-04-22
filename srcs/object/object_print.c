/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:16 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 11:40:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "twl_stdio.h"

void				object_print(t_object *object)
{
	twl_printf("===== Print Object =====\n");
	twl_printf("type: %s\n", object->type);
	twl_printf("red: %f\n", object->red);
	twl_printf("green: %f\n", object->green);
	twl_printf("blue: %f\n", object->blue);
	twl_printf("pos.x: %f\n", object->pos.x);
	twl_printf("pos.y: %f\n", object->pos.y);
	twl_printf("pos.z: %f\n", object->pos.z);
	twl_printf("rot_x: %f\n", object->rot_x);
	twl_printf("rot_y: %f\n", object->rot_y);
	twl_printf("rot_z: %f\n", object->rot_z);
	twl_printf("radius: %f\n", object->radius);
	twl_printf("size: %f\n", object->size);
	twl_printf("ambient: %f\n", object->ambient);
	twl_printf("diffuse: %f\n", object->diffuse);
	twl_printf("transparence: %f\n", object->transparence);
	twl_printf("reflection: %f\n", object->reflection);
	twl_printf("refraction: %f\n", object->refraction);
	twl_printf("xpm_texture_file: %s\n", object->texture.file);
	twl_printf("texture_offset_x: %f\n", object->texture.offset_x);
	twl_printf("texture_offset_y: %f\n", object->texture.offset_y);
	twl_printf("texture_stretch_x: %f\n", object->texture.stretch_x);
	twl_printf("texture_stretch_y: %f\n", object->texture.stretch_y);
	twl_printf("flip_normal: %d\n", object->flip_normal);
}
