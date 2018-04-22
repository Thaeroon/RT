/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:21:06 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 11:40:25 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "twl_stdio.h"



void				light_print(t_light *light)
{
	twl_printf("===== Light Print =====\n");
	twl_printf("pos.x: %f\n", light->pos.x);
	twl_printf("pos.y: %f\n", light->pos.y);
	twl_printf("pos.z: %f\n", light->pos.z);
	twl_printf("intensity: %f\n", light->intensity);
	twl_printf("red: %f\n", light->red);
	twl_printf("green: %f\n", light->green);
	twl_printf("blue: %f\n", light->blue);
}
