/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:58:36 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 19:01:30 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "twl_dict.h"
# include "xopt.h"
# include "twl_stdio.h"
# include "twl_xstdio.h"

void		*dict_get_with_default(t_dict *dict, char *key, void *def);
char		*read_raw_input();

#endif
