/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:11:15 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 13:17:38 by tbillon          ###   ########lyon.fr   */
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
}				t_resolve;

t_resolve	*initialize_resolve(void);

#endif