/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:17 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:22:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void				objects_del(t_lst *objects)
{
	twl_lst_del(objects, object_del);
}
