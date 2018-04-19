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
# define RAY_DEPTH 50
# define SKY_BACKGROUND 1
# define MIN_LIGHT 0
# define MIN_EMITED 0
# define NUMBER_OF_THREADS 100
# define LOADING_STEP 27

typedef struct s_ray
{
	t_vector	ori;
	t_vector	dir;
}			t_ray;

typedef struct s_hit_rec
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
    pthread_cond_t	progress;
} 				t_thread_arg;

void			draw_img(t_img *img, t_env *env, int i);

int		scatter(const t_ray *ray, t_hit_rec *rec, t_ray *scatter);
int		hit(t_env *env, const t_ray *ray, t_hit_rec *rec);
void	init_camera(t_camera *cam, float aspect);
#endif
