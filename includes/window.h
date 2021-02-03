/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:27:20 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 13:03:39 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

/* This file contains the window structure and all the functions relative to it's construction */

typedef	struct 	window
{
	int		res_x;			/* Resolution on x axis */
	int		res_y;			/* Resolution on y axis */
	char	*title;			/* Window title */
	void	*mlx_ptr;		/* pointer to location of current mlx instance */
	void	*win_ptr;		/* pointer to location of current window instance */
}				s_window;

s_window	*initialize_window(void);

#endif