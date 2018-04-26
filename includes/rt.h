/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:37:31 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 23:36:48 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>
# include <pthread.h>
# include "object.h"
# include "vector.h"
# include "camera.h"
# include "env.h"
# include "image.h"

# define MIN_CLOSEST 0.001

# define WIN_WIDTH 900
# define WIN_HEIGH 450
# define AA_STRENGH 50
# define RAY_DEPTH 10
# define MIN_EMITED 0
# define NUMBER_OF_THREADS 10
# define LOADING_STEP 27

typedef struct	s_ray
{
	t_vector	ori;
	t_vector	dir;
}				t_ray;
typedef struct	s_var
{
	float	closest;
	float	t1;
	float	t0;
	float	axe0;
	float	axe1;
	float	th;
}				t_var;
typedef struct	s_hit_rec
{
	float		t;
	float		u;
	float		v;
	t_vector	p;
	t_vector	normal;
	t_object	*obj_ptr;
}				t_hit_rec;

typedef struct	s_thread_arg
{
	int				i;
	int				thread_num;
	int				end;
	t_img			*img;
	t_env			*env;
	t_ray			*ray;
	pthread_mutex_t	mutex;
	pthread_t		*thread;
}				t_thread_arg;

t_vector		get_color(t_env *env, const t_ray *prim_ray, int depth);
void			draw_img(t_img *img, t_env *env, int i);
void			*thread_fnc(void *data);
int				scatter(const t_ray *ray, t_hit_rec *rec, t_ray *scatter);
int				hit(t_env *env, const t_ray *ray, t_hit_rec *rec);
void			init_camera(t_camera *cam, float aspect);
int				flip(t_thread_arg *thread_arg);
void			loading(int *loading_img_buffer, int reset);
int				key_hook(int k, t_clean_arg *clean_arg);
void			move_lr(int k, t_clean_arg *clean_arg);
void			move_ud(int k, t_clean_arg *clean_arg);
void			move_fb(int k, t_clean_arg *clean_arg);
void			rotate_x(int k, t_clean_arg *clean_arg);
void			rotate_y(int k, t_clean_arg *clean_arg);
void			fill_ppm(const int *buffer, int fd, int i);
int				get_fd(t_camera *camera);

#endif
