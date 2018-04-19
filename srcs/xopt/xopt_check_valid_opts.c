/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopt_check_valid_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:13:17 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:13:18 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xopt.h"

void				xopt_check_valid_opts(t_xopt *xopt)
{
	char			*first_not_valid_opt;

	first_not_valid_opt = twl_opt_check_invalid_opts(xopt->opt__);
	if (first_not_valid_opt)
	{
		twl_xprintf("Invalid Option: %s\n", first_not_valid_opt);
	}
}
