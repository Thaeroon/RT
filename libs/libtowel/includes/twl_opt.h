/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_OPT_H
# define TWL_OPT_H

# include "twl_lst.h"

typedef struct		s_opt
{
	char			*cmd;
	t_lst			*opts;
	t_lst			*args;
	char			*valid_opts;
}					t_opt;

t_opt				*twl_opt_new(char **argv, char *valid_opts);
void				twl_opt_del(t_opt *opt);
bool				twl_opt_exist(t_opt *opt, char *opt_key);
char				*twl_opt_check_invalid_opts(t_opt *opt);

char				**twl_opt_new_parse_arg_opt_and_return_non_opt_args__(
								char **arr_opts, t_opt *opt, char *valid_opts);
size_t				twl_opt_args_len(t_opt *opt);
char				*twl_opt_args_get(t_opt *opt, int index);
char				*twl_opt_get_param(t_opt *twl_opt, char *opt_key);

#endif
