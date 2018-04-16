#include "rt.h"
#include "texture.h"

static t_vector	background_color(int is_sky, const t_ray *prim_ray)
{
	t_vector	color;
	float		t;

	if (is_sky)
	{
		t = 0.5 * (normalise(prim_ray->dir).y + 1.0);
		color.x = (1.0 - t) + t * 0.5;
		color.y = (1.0 - t) + t * 0.7;
		color.z = (1.0 - t) + t * 1.0;
	}
	else
		color = new_vector(MIN_LIGHT,MIN_LIGHT,MIN_LIGHT);
	return (color);
}

t_vector		get_color(t_env *env, const t_ray *prim_ray, int depth)
{
	t_hit_rec		rec;
	t_ray			sec_ray;
	t_vector		emited;

	if (hit(env, prim_ray, &rec))
	{
		if (rec.obj_ptr->diffuse > 0)
		{
			emited.x = rec.obj_ptr->diffuse * rec.obj_ptr->red;
			emited.y = rec.obj_ptr->diffuse * rec.obj_ptr->green;
			emited.z = rec.obj_ptr->diffuse * rec.obj_ptr->blue;
		}
		else
			emited = new_vector(MIN_EMITED, MIN_EMITED, MIN_EMITED);
		if (depth < RAY_DEPTH && scatter(prim_ray, &rec, &sec_ray))
			return (get_texture(&rec, get_color(env, &sec_ray, depth + 1)));
		else
			return (emited);
	}
	else
		return (background_color(SKY_BACKGROUND, prim_ray));
}

static void		get_ray(t_ray *ray, t_camera *cam, int i, int j)
{
	float	u;
	float	v;

	u = (float)(i + drand48()) / (float)WIN_WIDTH;
	v = (float)(j + drand48()) / (float)WIN_HEIGH;
	ray->dir.x = cam->up_left.x + u * cam->hori.x - v * cam->vert.x - cam->pos.x;
	ray->dir.y = cam->up_left.y + u * cam->hori.y - v * cam->vert.y - cam->pos.y;
	ray->dir.z = cam->up_left.z + u * cam->hori.z - v * cam->vert.z - cam->pos.z;
}

void			*thread_fnc(void *data)
{
	int 			i;
	int				k;
	t_vector		col;
	t_thread_arg	*thread_arg;
	t_ray			ray;
	int				pix_per_thread;
	int				thread_num;
	int				x;
	int				y;

	thread_arg = (t_thread_arg*)data;
	pthread_mutex_lock(&thread_arg->mutex);
	thread_num = thread_arg->thread_num;
	thread_arg->thread_num += 1;
	ray = *thread_arg->ray;
	pthread_mutex_unlock(&thread_arg->mutex);
	pix_per_thread = WIN_HEIGH * WIN_WIDTH / NUMBER_OF_THREADS;
	i = -1;
	x = (thread_num * pix_per_thread) % WIN_WIDTH;
	y = (thread_num * pix_per_thread) / WIN_WIDTH;
	x--;
	while (++i < pix_per_thread)
	{
		if (++x >= WIN_WIDTH)
		{
			x = 0;
			y++;
		}
		k = -1;
		set_value_vector(&col, 0, 0, 0);
		while (++k < AA_STRENGH)
		{
			get_ray(&ray, thread_arg->env->camera, x, y);
			col = add_vector(col, get_color(thread_arg->env, &ray, 0));
		}
		col.x = col.x / (float)AA_STRENGH;
		col.y = col.y / (float)AA_STRENGH;
		col.z = col.z / (float)AA_STRENGH;
		put_pixel(thread_arg->img->buffer, x, y, &col);
		if ((thread_num * pix_per_thread + i) % (WIN_HEIGH * WIN_WIDTH / LOADING_STEP) == 0)
		{
			pthread_cond_signal(&thread_arg->progress);
		}
	}
    pthread_exit(NULL);
}

void			*loading(void *data)
{
	t_thread_arg	*thread_arg;
	int				i;
	t_vector		col;
	int				x;
	int				y;

	thread_arg = (t_thread_arg*)data;
	col = new_vector(1, 1, 1);
	i = 0;
	x = -1;
	while (!thread_arg->end)
	{
		pthread_cond_wait(&thread_arg->progress, &thread_arg->mutex);
		x = -1;
		while (++x < WIN_WIDTH / LOADING_STEP)
		{
			y = WIN_HEIGH - 16;
			while (++y < WIN_HEIGH)
				put_pixel(thread_arg->img->loading_img_buffer, x + i, y, &col);
		}
		mlx_put_image_to_window(thread_arg->img->mlx, thread_arg->img->win,
								thread_arg->img->loading_img_ptr, 0, 0);
		i += WIN_WIDTH / LOADING_STEP;
	}
    pthread_exit(NULL);
}

void			draw_img(t_img *img, t_env *env)
{
	t_ray			ray;
	t_thread_arg	thread_arg;
	pthread_t		*thread;
	int				i;
	int				j;

	(!(thread = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_THREADS + 1)))
														? exit(-1) : 0;
	thread_arg.ray = &ray;
	thread_arg.env = env;
	thread_arg.img = img;
	init_camera(env->camera, (float)WIN_WIDTH / (float)WIN_HEIGH);
	ray.ori.x = env->camera->pos.x;
	ray.ori.y = env->camera->pos.y;
	ray.ori.z = env->camera->pos.z;
	thread_arg.thread_num = 0;
	thread_arg.end = 0;
	j = -1;
	(pthread_create(&thread[NUMBER_OF_THREADS], NULL, loading, &thread_arg) != 0)
														? exit(3) : 0;
    pthread_mutex_init (&thread_arg.mutex, NULL);
    pthread_cond_init (&thread_arg.progress, NULL);
	while (++j < NUMBER_OF_THREADS)
		(pthread_create(&thread[j], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	i =-1;
	while (++i < NUMBER_OF_THREADS)
		pthread_join(thread[i], NULL);
	thread_arg.end = 1;
	pthread_cond_signal(&thread_arg.progress);
	pthread_join(thread[NUMBER_OF_THREADS], NULL);
	free(thread);
}