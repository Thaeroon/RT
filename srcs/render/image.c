/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:04:26 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:09:38 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		destroy_img(t_img *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->ptr);
	mlx_destroy_image(img->mlx, img->loading_img_ptr);
	free(img);
}

int			clean_quit(void *parram)
{
	destroy_img(parram);
	exit(0);
	return (0);
}

void		put_pixel(int *buffer, int x, int y, t_vector *col)
{
	int		color;

	if (buffer == NULL || x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGH)
		return ;
	color = (int)(255.99 * col->x) << 16;
	color += (int)(255.99 * col->y) << 8;
	color += (int)(255.99 * col->z);
	buffer[x + WIN_WIDTH * y] = color;
}

void		save_image(const t_camera *camera, const int *buffer)
{
	int		fd;
	int		i;
	int		col;

	if (!camera->save_as_ppm)
		return ;
	fd = open("output_rt.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	twl_putstr_fd("P3\n", fd);
	twl_putnbr_fd(WIN_WIDTH, fd);
	twl_putchar_fd(' ', fd);
	twl_putnbr_fd(WIN_HEIGH, fd);
	twl_putstr_fd("\n255\n", fd);
	i = -1;
	while (++i < WIN_WIDTH * WIN_HEIGH)
	{
		col = (buffer[i] >> 16) & 0xFF;
		twl_putnbr_fd(col, fd);
		twl_putchar_fd(' ', fd);
		col = (buffer[i] >> 8) & 0xFF;
		twl_putnbr_fd(col, fd);
		twl_putchar_fd(' ', fd);
		col = buffer[i] & 0xFF;
		twl_putnbr_fd(col, fd);
		twl_putchar_fd('\n', fd);
	}
}

void		apply_filter(const t_camera *camera, t_vector *col)
{
	t_vector	col_tmp;

	if (camera->sepia_filter)
	{
		col_tmp = *col;
		col->x = (col_tmp.x * 0.393) + (col_tmp.y * 0.769)
					+ (col_tmp.z * 0.189);
		col->y = (col_tmp.x * 0.349) + (col_tmp.y * 0.686)
					+ (col_tmp.z * 0.168);
		col->z = (col_tmp.x * 0.272) + (col_tmp.y * 0.534)
					+ (col_tmp.z * 0.131);
	}
}
