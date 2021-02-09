/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 10:05:22 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_square	*initialize_square(void)
{
	t_square	*new_square;

	if (!(new_square = ft_calloc(sizeof(t_square), 1)))
		return (NULL);
	new_square->coord = initialize_vector();
	new_square->orientation = initialize_vector();
	new_square->height = 0.0;
	new_square->color = initialize_colors();
	return (new_square);
}

int	check_square_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[0]) && check_coordinates(data[1]))
		if ((ft_atof(data[2]) > 0.0) && (count_comma_format(data[3]) == 2))
			if (count_nb_format(data[3]) <= 9)
				return (1);
	error_code(3, type);
	return (0);
}

int	parse_square_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;
	char	**coord;
	char	**orientation;
	char	**color;

	data = ft_split(str, " \t");
	coord = ft_split(data[0], ",");
	orientation = ft_split(data[1], ",");
	color = ft_split(data[3], ",");
	if (check_square_format(str, type, data) == 1)
	{
		mini_rt->sq->coord->x = ft_atof(coord[0]);
		mini_rt->sq->coord->y = ft_atof(coord[1]);
		mini_rt->sq->coord->z = ft_atof(coord[2]);
		mini_rt->sq->orientation->x = ft_atof(orientation[0]);
		mini_rt->sq->orientation->y = ft_atof(orientation[1]);
		mini_rt->sq->orientation->z = ft_atof(orientation[2]);
		mini_rt->sq->height = ft_atof(data[2]);
		mini_rt->sq->color->r = ft_atof(color[0]);
		mini_rt->sq->color->g = ft_atof(color[1]);
		mini_rt->sq->color->b = ft_atof(color[2]);
		ft_putstr("SQUARE DONE\n");
		return (1);
	}
	return (0);
}
