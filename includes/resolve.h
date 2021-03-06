/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:11:15 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/01 12:33:02 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
#define RESOLVE_H

#include "utils.h"

typedef	struct	s_resolve
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	t_res;
	double	deamon;
	t_vectors	sub;
	t_vectors	sub_2;
	t_vectors	hit;
	t_vectors	cross;
}				t_resolve;

t_resolve	*initialize_resolve(void);

#endif