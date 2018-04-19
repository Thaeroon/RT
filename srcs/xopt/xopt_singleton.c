/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopt_singleton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:13:36 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:13:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xopt.h"

t_xopt				*xopt_singleton(void)
{
	static t_xopt	*xopt = NULL;

	if (!xopt)
		xopt = xopt_new();
	return (xopt);
}
