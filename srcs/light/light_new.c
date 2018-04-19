/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:21:01 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:21:30 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "twl_xstdlib.h"

t_light				*light_new(void)
{
	t_light			*light;

	light = twl_malloc_x0(sizeof(t_light));
	light->pos.x = 0.0;
	light->pos.y = 0.0;
	light->pos.z = 0.0;
	light->intensity = 0.0;
	light->red = 0.0;
	light->green = 0.0;
	light->blue = 0.0;
	return (light);
}
