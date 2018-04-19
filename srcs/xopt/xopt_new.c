/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopt_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:13:31 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:13:32 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xopt.h"

t_xopt				*xopt_new(void)
{
	t_xopt			*xopt;

	xopt = twl_malloc_x0(sizeof(t_xopt));
	xopt->file_argument = NULL;
	return (xopt);
}
