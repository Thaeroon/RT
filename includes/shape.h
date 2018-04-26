/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:55:13 by nmuller           #+#    #+#             */
/*   Updated: 2018/04/22 16:26:56 by afertah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H
# include "rt.h"

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
void		point_at(const t_ray *ray, float t, t_vector *tmp);
int			cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			decoupage(t_object *object, t_ray r, t_hit_rec *rec, t_var var);
int			rotation_x(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			rotation_y(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			rotation_z(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			xy_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			yz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			xz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			cube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			translate(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			object_hit(t_object *object, const t_ray *ray, t_hit_rec *rec,
										float closest);
int			plan_y(t_object *object, const t_ray *ray, t_hit_rec *rec,
																float closest);
int			cone_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			cone_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			cone_neg_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			sphere_neg_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			cube_neg_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			cylindre_neg_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			capsule_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
void		swap_temp(float *temp0, float *temp1, t_object *object);
#endif
