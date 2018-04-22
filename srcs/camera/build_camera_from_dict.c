/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera_from_dict.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:08:23 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:44:38 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "utils.h"
#include <stdlib.h>
#include "twl_stdio.h"

static void			suite(t_camera *camera, t_dict *dict)
{
	char		*ret_val;

	ret_val = dict_get_with_default(dict, "sepia_filter", "0");
	camera->sepia_filter = atoi(ret_val);
	ret_val = dict_get_with_default(dict, "save_as_ppm", "0");
	camera->save_as_ppm = atoi(ret_val);
	ret_val = dict_get_with_default(dict, "sky_background", "1");
	camera->sky_background = atof(ret_val);
	ret_val = dict_get_with_default(dict, "min_illumination", "0");
	camera->min_illumination = atof(ret_val);
	ret_val = dict_get_with_default(dict, "save", "0");
	camera->min_illumination = atoi(ret_val);
}

void				build_camera_from_dict(t_camera *camera, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "pos.x", "0");
	camera->pos.x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.y", "0");
	camera->pos.y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.z", "0");
	camera->pos.z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_x", "0");
	camera->dir_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_y", "0");
	camera->dir_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_z", "0");
	camera->dir_z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "fov", "90");
	camera->fov = atof(ret_val);
	ret_val = dict_get_with_default(dict, "up_x", "0");
	camera->up_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "up_y", "1");
	camera->up_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "up_z", "0");
	camera->up_z = atof(ret_val);
	suite(camera, dict);
}
