/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:14:15 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:15:16 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static char			*get_raw_input(void)
{
	char			*raw_input;

	if (xopt_singleton()->file_argument)
	{
		raw_input = twl_file_to_str(xopt_singleton()->file_argument);
	}
	else
	{
		twl_printf("If you haven't pipe any content in the stdin,\
													please hit ctrl + D\n");
		raw_input = twl_fd_to_str(STDIN_FILENO);
	}
	return (raw_input);
}

char				*read_raw_input(void)
{
	char			*raw_input;

	raw_input = get_raw_input();
	if (!raw_input || twl_strlen(raw_input) == 0)
		twl_xprintf("Empty input");
	return (raw_input);
}
