/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:08:43 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:44:44 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "twl_xstdlib.h"

t_camera			*camera_new(void)
{
	t_camera		*camera;

	camera = twl_malloc_x0(sizeof(t_camera));
	camera->pos.x = 0.0;
	camera->pos.y = 0.0;
	camera->pos.z = 0.0;
	camera->dir_x = 0.0;
	camera->dir_y = 0.0;
	camera->dir_z = 0.0;
	camera->fov = 0.0;
	camera->up_x = 0.0;
	camera->up_y = 0.0;
	camera->up_z = 0.0;
	camera->sepia_filter = 0;
	camera->save_as_ppm = 0;
	camera->sky_background = 1;
	camera->min_illumination = 0;
	return (camera);
}
