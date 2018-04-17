#include "texture.h"

static t_vector	get_constant_texture(const t_hit_rec *rec, t_vector ret)
{
	ret.x = rec->obj_ptr->red * ret.x;
	ret.y = rec->obj_ptr->green * ret.y;
	ret.z = rec->obj_ptr->blue * ret.z;
	return (ret);
}

static t_vector	get_xpm_texture(const t_hit_rec *rec, t_vector ret)
{
	int			i;
	int			j;
	int			color;
	t_tex		tex;

	tex = rec->obj_ptr->texture;
	i = rec->u * tex.width / tex.stretch_x - tex.offset_x;
	j = (1 - rec->v) * tex.height / tex.stretch_y - tex.offset_y;
	if (i < 0 || j < 0 || i > tex.width - 1 || j > tex.height - 1)
	{
		ret.x = rec->obj_ptr->red * ret.x;
		ret.y = rec->obj_ptr->green * ret.y;
		ret.z = rec->obj_ptr->blue * ret.z;
	}
	else
	{
		color = tex.buffer[i + tex.width * j];
		ret.x = (((color >> 16) & 0x0000FF) / 255.0) * ret.x;
		ret.y = (((color >> 8) & 0x0000FF) / 255.0) * ret.y;
		ret.z = ((color & 0x0000FF) / 255.0) * ret.z;
	}
	return (ret);
}

static t_vector	get_checker_texture(const t_hit_rec *rec, t_vector ret)
{
	float		sines;

	sines = sin(10 * rec->p.x) * sin(10 * rec->p.y) * sin(10 * rec->p.z);
	if (sines > 0)
	{
		ret.x = rec->obj_ptr->red * ret.x;
		ret.y = rec->obj_ptr->green * ret.y;
		ret.z = rec->obj_ptr->blue * ret.z;
	}
	else
	{
		ret.x = rec->obj_ptr->red * ret.x / 2;
		ret.y = rec->obj_ptr->green * ret.y / 2;
		ret.z = rec->obj_ptr->blue * ret.z / 2;
	}
	return (ret);
}

t_vector		get_texture(const t_hit_rec *rec, t_vector ret)
{
	if (rec->obj_ptr->texture.buffer == 0)
		if (twl_strcmp(rec->obj_ptr->texture.file, "checker") == 0)
			return (get_checker_texture(rec, ret));
		else
			return (get_constant_texture(rec, ret));
	else
		return (get_xpm_texture(rec, ret));
}

void			set_texture(const t_env *env, t_img *img)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	t_object		*obj;


	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		obj = ((t_object*)elem->data);
		obj->texture.ptr = mlx_xpm_file_to_image(img->mlx,
			obj->texture.file, &obj->texture.width, &obj->texture.height);
		if (obj->texture.ptr)
			obj->texture.buffer = (int*)mlx_get_data_addr(obj->texture.ptr,
				&(obj->texture.bpp), &(obj->texture.line_s),
				&(obj->texture.endian));
		elem = next;
	}
}

void			free_texture(const t_env *env, t_img *img)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	t_object		*obj;


	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		obj = ((t_object*)elem->data);
		if (obj->texture.ptr)
			mlx_destroy_image(img->mlx, obj->texture.ptr);
		elem = next;
	}
}