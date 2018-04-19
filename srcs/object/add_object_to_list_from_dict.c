/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_to_list_from_dict.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:09 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:22:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void				add_object_to_list_from_dict(t_lst *objects, t_dict *object)
{
	t_object		*new_object;

	new_object = object_new();
	build_object_from_dict(new_object, object);
	twl_lst_push_back(objects, new_object);
}
