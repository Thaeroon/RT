/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:08:58 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:14:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"
#include <math.h>

void	init_camera(t_camera *cam, float aspect)
{
	float		half_height;
	float		half_width;
	t_vector	u;
	t_vector	v;
	t_vector	w;

	half_height = tan((cam->fov * M_PI / 180) / 2);
	half_width = aspect * half_height;
	w.x = cam->pos.x - cam->dir_x;
	w.y = cam->pos.y - cam->dir_y;
	w.z = cam->pos.z - cam->dir_z;
	w = normalise(w);
	u = prod_vector(new_vector(cam->up_x, cam->up_y, cam->up_z), w);
	u = normalise(u);
	v = prod_vector(w, u);
	cam->up_left.x = cam->pos.x - half_width * u.x + half_height * v.x - w.x;
	cam->up_left.y = cam->pos.y - half_width * u.y + half_height * v.y - w.y;
	cam->up_left.z = cam->pos.z - half_width * u.z + half_height * v.z - w.z;
	cam->hori.x = 2.0 * half_width * u.x;
	cam->hori.y = 2.0 * half_width * u.y;
	cam->hori.z = 2.0 * half_width * u.z;
	cam->vert.x = 2.0 * half_height * v.x;
	cam->vert.y = 2.0 * half_height * v.y;
	cam->vert.z = 2.0 * half_height * v.z;
}
