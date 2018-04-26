/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light_from_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:20:53 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 19:18:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "utils.h"
#include <stdlib.h>

void				build_light_from_dict(t_light *light, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "pos.x", "0");
	light->pos.x = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.y", "0");
	light->pos.y = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos.z", "0");
	light->pos.z = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "intensity", "0");
	light->intensity = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "red", "0");
	light->red = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "green", "0");
	light->green = twl_atof(ret_val);
	ret_val = dict_get_with_default(dict, "blue", "0");
	light->blue = twl_atof(ret_val);
}
