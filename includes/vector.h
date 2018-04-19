/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:01:54 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:02:04 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef	struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

t_vector		new_vector(float x, float y, float z);
t_vector		add_vector(t_vector a, t_vector b);
t_vector		mult_vector(t_vector a, t_vector b);
t_vector		prod_vector(t_vector a, t_vector b);
t_vector		prod_float(t_vector a, float f);
float			scal_prod(const t_vector *a, const t_vector *b);
float			norm(const t_vector *a);
void			set_value_vector(t_vector *vect, float x, float y, float z);
t_vector		normalise(t_vector a);
#endif
