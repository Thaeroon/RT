/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_to_list_from_dict.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:20:48 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:20:49 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void				add_light_to_list_from_dict(t_lst *lights, t_dict *light)
{
	t_light			*new_light;

	new_light = light_new();
	build_light_from_dict(new_light, light);
	twl_lst_push_back(lights, new_light);
}
