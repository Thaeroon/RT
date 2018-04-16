#include "env.h"


static void			free_dict_wrapper(void *elem_)
{
	t_dict			*elem;

	elem = (t_dict *)elem_;
	twl_dict_del(elem, free);
}

static int			is_valid_type(char *type)
{
	char			**types;
	void			*find;

	types = twl_strsplit(VALIDE_TYPE, ',');
	find = twl_arr_find(types, twl_strequ_void, type);
	twl_arr_del(types, free);
	if (find)
		return (1);
	return (0);
}

static char			*clean_char(char *str, char *match_chars)
{
	char 			*new_str;
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

static void			populate_env(void *elem, void *ctx)
{
	char			*type;

	type = twl_dict_get((t_dict *)elem, "type");
	if (!is_valid_type(type))
	{
		twl_dprintf(2, "Invalide type: %s. Object will be skipped\n", type);
		return ;
	}
	if (twl_strcmp(type, "camera") == 0)
		build_camera_from_dict(((t_env *)ctx)->camera, (t_dict *)elem);
	else if (twl_strcmp(type, "light") == 0)
		add_light_to_list_from_dict(((t_env *)ctx)->lights, (t_dict *)elem);
	else
		add_object_to_list_from_dict(((t_env *)ctx)->objects, (t_dict *)elem);
}

static void			create_dict_entry(void *elem, void *ctx)
{
	char 			*str;
	char 			**split;
	t_dict 			*dict;

	str = (char *)elem;
	dict = (t_dict *)ctx;
	split = twl_strsplit(str, ':');
	if (twl_arr_len(split) == 2)
		twl_dict_add(dict, split[0], twl_strdup(split[1]));
	twl_arr_del(split, free);
}

static void			parse_fn(void *elem, void *ctx)
{
	char 			*str;
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
		return;
	}
	twl_lst_push_back((t_lst *)ctx, dict);
}

void				env_fill(t_env *env)
{
	char 			*json;
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
