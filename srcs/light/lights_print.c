/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:21:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:21:18 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static void			print_fn(void *elem)
{
	light_print((t_light *)elem);
}

void				lights_print(t_lst *lights)
{
	twl_lst_iter0(lights, print_fn);
}
