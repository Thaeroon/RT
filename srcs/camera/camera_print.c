/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:08:47 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:45:50 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "twl_stdio.h"

void				camera_print(t_camera *camera)
{
	twl_printf("====== Camera print ======\n");
	twl_printf("pos.x: %f\n", camera->pos.x);
	twl_printf("pos.y: %f\n", camera->pos.y);
	twl_printf("pos.z: %f\n", camera->pos.z);
	twl_printf("dir_x: %f\n", camera->dir_x);
	twl_printf("dir_y: %f\n", camera->dir_y);
	twl_printf("dir_z: %f\n", camera->dir_z);
	twl_printf("fov  : %f\n", camera->fov);
	twl_printf("up_x : %f\n", camera->up_x);
	twl_printf("up_y : %f\n", camera->up_y);
	twl_printf("up_z : %f\n", camera->up_z);
	twl_printf("save_as_ppm : %f\n", camera->save_as_ppm);
	twl_printf("sky_background : %f\n", camera->sky_background);
	twl_printf("min_illumination : %f\n", camera->min_illumination);
}
