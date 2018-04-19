/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:18 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:22:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void			print_fn(void *elem)
{
	object_print((t_object *)elem);
}

void				objects_print(t_lst *objects)
{
	twl_lst_iter0(objects, print_fn);
}
