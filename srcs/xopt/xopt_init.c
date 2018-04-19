/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopt_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:13:27 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:13:27 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xopt.h"

void				print_usage(void)
{
	twl_printf("usage: ./rt [file]\n");
	twl_printf("\tThe program accepts both stdin (pipe or <) and file\n");
	twl_printf("options:\n");
	twl_printf("\t-h           Help.\n");
}

void				xopt_init(t_xopt *xopt, char **av)
{
	xopt->opt__ = twl_opt_new(av, XOPT_VALID_OPTS);
	xopt_check_valid_opts(xopt);
	if (twl_opt_exist(xopt->opt__, "h"))
	{
		print_usage();
		exit(0);
	}
	if (twl_opt_args_len(xopt->opt__) > 0)
	{
		xopt->file_argument = twl_strdup(twl_opt_args_get(xopt->opt__, 0));
	}
}
