/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:22:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:22:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdlib.h>

void				object_del(t_object *object)
{
	free(object->type);
	free(object->texture.file);
	free(object);
}
