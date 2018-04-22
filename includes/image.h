/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:51:51 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/21 14:36:20 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}				t_img;

typedef struct	s_clean_arg
{
	t_img		*img;
	t_env		*env;
	int			*end;
	pthread_t	wait_thread;
}				t_clean_arg;

int				clean_quit(t_clean_arg *clean_arg);
void			put_pixel(int *buffer, int x, int y, t_vector *col);
void			apply_filter(const t_camera *env, t_vector *col);
void			save_image(t_camera *camera, const int *buffer);

#endif
