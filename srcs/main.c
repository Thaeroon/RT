/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:02:43 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 23:44:02 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "xopt.h"
#include "rt.h"
#include "texture.h"

int				key_hook(int k, t_clean_arg *clean_arg)
{
	if (k == 53)
		clean_quit(clean_arg);
	if (k == 65307)
		clean_quit(clean_arg);
	if (k == 35)
		save_image(clean_arg->env->camera, clean_arg->img->buffer);
	if (!*clean_arg->end)
		return (0);
	loading(clean_arg->img->loading_img_buffer, 1);
	if (k == 0 || k == 2)
		move_lr(k, clean_arg);
	if (k == 8 || k == 49)
		move_ud(k, clean_arg);
	if (k == 1 || k == 13)
		move_fb(k, clean_arg);
	if (k == 125 || k == 126)
		rotate_x(k, clean_arg);
	if (k == 123 || k == 124)
		rotate_y(k, clean_arg);
	return (0);
}

int				flip(t_thread_arg *thread_arg)
{
	usleep(100000);
	if (!thread_arg->end)
		mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
								thread_arg->img->loading_img_ptr, 0, 0);
	else
		mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
								thread_arg->img->ptr, 0, 0);
	return (0);
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
	return (0);
	(void)ac;
}
