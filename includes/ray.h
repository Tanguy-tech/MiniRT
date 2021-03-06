/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:24:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/06 10:34:02 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vectors.h"
#include "scenes.h"

typedef	struct ray
{
	t_vectors	*origin;	/* Origin point of the ray (vector point) */
	t_vectors	*direction;	/* Direction of the ray (vector) */
}				t_ray;

t_ray	*initialize_ray(void);
t_ray	*generate_new_ray(t_scene	*mini_rt);
void	update_ray(t_ray	*ray, t_scene *mini_rt, double index_hor, double index_ver);

#endif