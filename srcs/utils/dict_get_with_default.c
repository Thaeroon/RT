/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_with_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:14:12 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:14:12 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void				*dict_get_with_default(t_dict *dict, char *key, void *def)
{
	t_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (elem->data);
		elem = elem->next;
	}
	return (def);
}
