/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:39:51 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/26 20:42:39 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				rotate_x(int k, t_clean_arg *clean_arg)
{
	if (k == 125)
		clean_arg->env->camera->dir_y -= 1;
	else if (k == 126)
		clean_arg->env->camera->dir_y += 1;
	draw_img(clean_arg->img, clean_arg->env, -1);
}

void				rotate_y(int k, t_clean_arg *clean_arg)
{
	if (k == 124)
		clean_arg->env->camera->dir_x += 1;
	else if (k == 123)
		clean_arg->env->camera->dir_x -= 1;
	draw_img(clean_arg->img, clean_arg->env, -1);
}
