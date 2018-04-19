/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:53:35 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 18:54:03 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "twl_lst.h"
# include "twl_dict.h"
# include "vector.h"

typedef struct		s_light
{
	t_vector		pos;
	float			intensity;
	float			red;
	float			green;
	float			blue;
}					t_light;

t_light				*light_new();
void				light_del(t_light *light);
void				lights_del(t_lst *light);

void				build_light_from_dict(t_light *light, t_dict *dict);
void				add_light_to_list_from_dict(t_lst *lst, t_dict *dict);

void				lights_print(t_lst *lights);
void				light_print(t_light *light);
#endif
