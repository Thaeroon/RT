/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:17:53 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:19:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int		is_valid_type(char *type)
{
	char			**types;
	void			*find;

	types = twl_strsplit(VALIDE_TYPE, ',');
	find = twl_arr_find(types, twl_strequ_void, type);
	twl_arr_del(types, free);
	if (find)
		return (1);
	return (0);
}

void			populate_env(void *elem, void *ctx)
{
	char			*type;

	type = twl_dict_get((t_dict *)elem, "type");
	if (!is_valid_type(type))
	{
		twl_dprintf(2, "Invalide type: %s. Object will be skipped\n", type);
		return ;
	}
	if (twl_strcmp(type, "camera") == 0)
		build_camera_from_dict(((t_env *)ctx)->camera, (t_dict *)elem);
	else if (twl_strcmp(type, "light") == 0)
		add_light_to_list_from_dict(((t_env *)ctx)->lights, (t_dict *)elem);
	else
		add_object_to_list_from_dict(((t_env *)ctx)->objects, (t_dict *)elem);
}
