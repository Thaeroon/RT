#ifndef IMAGE_H
# define IMAGE_H
# include "vector.h"
# include "../minilibx/includes/mlx.h"

typedef struct	s_img
{
	void		*ptr;
	int			*buffer;
	int			bpp;
	int			line_s;
	int			endian;
	void		*win;
	void		*mlx;
	int			*loading_img_buffer;
	void		*loading_img_ptr;
} 				t_img;

void		destroy_img(t_img *img);
int			clean_quit(void *parram);
void		put_pixel(int *buffer, int x, int y, t_vector *col);
void		apply_filter(const t_camera *env, t_vector *col);
void		apply_gamma(t_vector *col);
void		save_image(const t_camera *camera, const int *buffer);

#endif
