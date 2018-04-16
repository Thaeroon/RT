
#include "env.h"
#include "xopt.h"
#include "rt.h"
#include "texture.h"

static int			key_hook(int k, t_img *img)
{
	if (k == 53)
		clean_quit(img);
	if (k == 65307)
		clean_quit(img);
	return (0);
}

int 				main(int ac, char **av)
{
	t_env			*env;
	t_img			*img;

	xopt_init(xopt_singleton(), av);
	env = env_new();
	env_print(env);
	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, "RT");
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
														&(img->endian));
	img->loading_img_ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->loading_img_buffer = (int*)mlx_get_data_addr(img->loading_img_ptr, &(img->bpp), &(img->line_s),
														&(img->endian));
	mlx_hook(img->win, 17, 0, clean_quit, img);
	mlx_key_hook(img->win, key_hook, img);
	set_texture(env, img);
	draw_img(img, env);
	mlx_put_image_to_window(img->mlx, img->win, img->ptr, 0, 0);
	free_texture(env, img);
	env_del(env);
	xopt_del(xopt_singleton());
	mlx_loop(img->mlx);
	destroy_img(img);
	return (0);
	(void)ac;
}
