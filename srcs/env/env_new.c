/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:15:54 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:16:23 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "twl_xstdlib.h"

t_env		*env_new(void)
{
	t_env	*env;

	env = twl_malloc_x0(sizeof(t_env));
	env->camera = camera_new();
	env->lights = twl_lst_new();
	env->objects = twl_lst_new();
	env_fill(env);
	return (env);
}
