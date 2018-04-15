#ifndef __OBJECT_H__
# define __OBJECT_H__

#include "twl_dict.h"
#include "twl_lst.h"
#include <math.h>
#include "vector.h"

typedef struct 		s_tex
{
	void			*ptr;
	char			*file;
	int				*buffer;
	int				bpp;
	int				line_s;
	int				endian;
	int				width;
	int				height;
}					t_tex;

typedef struct 		s_object
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
}					t_object;

t_object			*object_new();
void				object_del(t_object *object);
void				objects_del(t_lst *objects);

void				build_object_from_dict(t_object *object, t_dict *dict);
void 				add_object_to_list_from_dict(t_lst *objects, t_dict *object);


void				objects_print(t_lst *objects);
void				object_print(t_object *object);
#endif
