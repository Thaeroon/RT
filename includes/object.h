/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:56:38 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 20:06:50 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "twl_dict.h"
# include "twl_lst.h"
# include <math.h>
# include "vector.h"

typedef struct		s_tex
{
	void			*ptr;
	char			*file;
	int				*buffer;
	int				bpp;
	int				line_s;
	int				endian;
	int				width;
	int				height;
	float			offset_x;
	float			offset_y;
	float			stretch_x;
	float			stretch_y;
}					t_tex;

typedef struct		s_object
{
	char			*type;
	float			red;
	float			green;
	float			blue;
	t_vector		pos;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	float			radius;
	float			size;
	float			ambient;
	float			diffuse;
	float			transparence;
	float			reflection;
	float			refraction;
	t_tex			texture;
	int				flip_normal;
	float			cut_lvl;
	char			cut_axe;
	float			size_coup;
}					t_object;

t_object			*object_new();
void				object_del(t_object *object);
void				objects_del(t_lst *objects);

void				build_object_from_dict(t_object *object, t_dict *dict);
void				add_object_to_list_from_dict(t_lst *objects,
															t_dict *object);

void				objects_print(t_lst *objects);
void				object_print(t_object *object);
#endif
