/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:15:39 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/19 20:15:39 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

void				env_del(t_env *env)
{
	camera_del(env->camera);
	lights_del(env->lights);
	objects_del(env->objects);
	free(env);
}
