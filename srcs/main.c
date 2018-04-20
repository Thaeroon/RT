/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:02:43 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/20 17:55:49 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "xopt.h"
#include "rt.h"
#include "texture.h"

static int		key_hook(int k, t_img *img)
{
	if (k == 53)
		clean_quit(img);
	if (k == 65307)
		clean_quit(img);
	return (0);
}

static void		free_texture(const t_env *env, t_img *img)
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

static void		init_img(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, "RT");
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
														&(img->endian));
	img->loading_img_ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->loading_img_buffer = (int*)mlx_get_data_addr(img->loading_img_ptr,
								&(img->bpp), &(img->line_s), &(img->endian));
	mlx_hook(img->win, 17, 0, clean_quit, img);
	mlx_key_hook(img->win, key_hook, img);
}

int				main(int ac, char **av)
{
	t_env			*env;
	t_img			*img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	xopt_init(xopt_singleton(), av);
	env = env_new();
	env_print(env);
	init_img(img);
	set_texture(env, img);
	draw_img(img, env, -1);
	free_texture(env, img);
	env_del(env);
	xopt_del(xopt_singleton());
	destroy_img(img);
	return (0);
	(void)ac;
}
