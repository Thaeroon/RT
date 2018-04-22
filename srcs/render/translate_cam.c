#include "rt.h"

void				move_lr(int k, t_clean_arg *clean_arg)
{
	if (k == 0)
		clean_arg->env->camera->pos.x -= 0.2;
	else if (k == 1)
		clean_arg->env->camera->pos.x += 0.2;
	draw_img(clean_arg->img, clean_arg->env, -1);
}

void				move_ud(int k, t_clean_arg *clean_arg)
{
	if (k == 8)
		clean_arg->env->camera->pos.y -= 0.2;
	else if (k == 49)
		clean_arg->env->camera->pos.y += 0.2;
	draw_img(clean_arg->img, clean_arg->env, -1);
}

void				move_fb(int k, t_clean_arg *clean_arg)
{
	if (k == 13)
		clean_arg->env->camera->pos.z -= 0.2;
	else if (k == 1)
		clean_arg->env->camera->pos.z += 0.2;
	draw_img(clean_arg->img, clean_arg->env, -1);
}