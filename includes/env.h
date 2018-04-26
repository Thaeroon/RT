/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:44:02 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/26 17:12:52 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "camera.h"
# include "light.h"
# include "object.h"
# include "twl_arr.h"
# include "twl_lst.h"
# include "utils.h"

# define V1 "camera,light,plane,sphere,cylindre,tube,plan,"
# define V2 "x_rectangle,y_rectangle,z_rectangle,cube,cone,cone_coup,"
# define VALIDE_TYPE V1"cone_neg,cube_neg,cylindre_neg,sphere_neg,sphere_coup"

typedef struct	s_env
{
	t_camera		*camera;
	t_lst			*lights;
	t_lst			*objects;

}				t_env;

t_env			*env_new();
void			env_fill(t_env *env);
void			env_del(t_env *env);
void			populate_env(void *elem, void *ctx);
void			env_print(t_env *env);

#endif
