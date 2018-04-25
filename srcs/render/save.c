/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:40:10 by pbeller           #+#    #+#             */
/*   Updated: 2018/04/25 11:38:52 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int					get_fd(t_camera *camera)
{
	int				fd;
	char			*path;
	char			*index;

	camera->save += 1;
	path = twl_strdup("output_rt");
	index = twl_itoa(camera->save);
	path = twl_strjoinfree(path, index, 'b');
	path = twl_strjoinfree(path, ".ppm", 'l');
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	free(path);
	return (fd);
}

void				fill_ppm(const int *buffer, int fd, int i)
{
	int				col;

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
