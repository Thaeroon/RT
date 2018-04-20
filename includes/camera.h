/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:43:01 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 15:39:38 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "twl_dict.h"
# include "vector.h"

typedef struct	s_camera
{
	t_vector		pos;
	float			dir_x;
	float			dir_y;
	float			dir_z;
	float			fov;
	float			up_x;
	float			up_y;
	float			up_z;
	t_vector		hori;
	t_vector		vert;
	t_vector		up_left;
	int				sepia_filter;
	int				save_as_ppm;
	int				sky_background;
	int				min_illumination;
}				t_camera;

t_camera		*camera_new();
void			camera_del(t_camera *camera);

void			build_camera_from_dict(t_camera *camera, t_dict *dict);
void			camera_print(t_camera *camera);

#endif
