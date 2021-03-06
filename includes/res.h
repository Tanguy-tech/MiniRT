/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:18:44 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 14:33:08 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RES_H
#define RES_H

typedef	struct	s_res
{
	int	x;
	int	y;
	int	orig_x;
	double	ratio;
}				t_res;

t_res	*initialize_res(void);

#endif