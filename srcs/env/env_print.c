/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:15:58 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 11:40:31 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_print(t_env *env)
{
	camera_print(env->camera);
	lights_print(env->lights);
	objects_print(env->objects);
}
