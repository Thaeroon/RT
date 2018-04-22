/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:11:39 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 22:08:17 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	add_vector(t_vector a, t_vector b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	return (a);
}

t_vector	cross(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.y * b.z - b.y * a.z;
	c.y = a.z * b.x - b.z * a.x;
	c.z = a.x * b.y - b.x * a.y;
	return (c);
}

t_vector	mult_vect_float(t_vector a, float f)
{
	a.x = a.x * f;
	a.y = a.y * f;
	a.z = a.z * f;
	return (a);
}

t_vector	mult_vector(t_vector a, t_vector b)
{
	a.x = a.x * b.x;
	a.y = a.y * b.y;
	a.z = a.z * b.z;
	return (a);
}

float		dot(const t_vector *a, const t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
