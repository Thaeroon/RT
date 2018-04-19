/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:15:46 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:20:02 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void			free_dict_wrapper(void *elem_)
{
	t_dict			*elem;

	elem = (t_dict *)elem_;
	twl_dict_del(elem, free);
}

static char			*clean_char(char *str, char *match_chars)
{
	char			*new_str;
	char			*ret_str;
	int				i;

	new_str = twl_malloc_x0(twl_strlen(str) + 1);
	i = 0;
	while (*str)
	{
		if (!twl_strchr(match_chars, *str))
		{
			new_str[i] = *str;
			i++;
		}
		str++;
	}
	ret_str = twl_strdup(new_str);
	free(new_str);
	return (ret_str);
}

static void			create_dict_entry(void *elem, void *ctx)
{
	char			*str;
	char			**split;
	t_dict			*dict;

	str = (char *)elem;
	dict = (t_dict *)ctx;
	split = twl_strsplit(str, ':');
	if (twl_arr_len(split) == 2)
		twl_dict_add(dict, split[0], twl_strdup(split[1]));
	twl_arr_del(split, free);
}

static void			parse_fn(void *elem, void *ctx)
{
	char			*str;
	char			**split;
	t_dict			*dict;

	dict = twl_dict_new();
	str = clean_char((char *)elem, "{}[] \t\n");
	split = twl_strsplit(str, ',');
	free(str);
	twl_arr_iter(split, create_dict_entry, dict);
	twl_arr_del(split, free);
	if (twl_dict_len(dict) < 1)
	{
		free(dict);
		return ;
	}
	twl_lst_push_back((t_lst *)ctx, dict);
}

void				env_fill(t_env *env)
{
	char			*json;
	char			**split;
	t_lst			*lst;

	json = read_raw_input();
	split = twl_strsplit_mul_trim_chars(json, "{", "[]");
	free(json);
	lst = twl_lst_new();
	twl_arr_iter(split, parse_fn, lst);
	twl_arr_del(split, free);
	twl_lst_iter(lst, populate_env, env);
	twl_lst_del(lst, free_dict_wrapper);
}
