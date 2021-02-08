/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:59:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 15:53:14 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_sphere	*initialize_sphere(void)
{
	t_sphere	*new_sphere;

	if (!(new_sphere = ft_calloc(sizeof(t_sphere), 1)))
		return (NULL);
	new_sphere->color = initialize_colors();
	new_sphere->diam = 0.0;
	new_sphere->origin_coord = initialize_vector();
	return (new_sphere);
}


/* Check sphere format */
int	check_sphere_format(char *str, char *type)
{
	char	**data;

	data= ft_split(str, " \t");
	if (check_coordinates(data[0]) && count_double(data[1]) == 1 && (count_comma_format(data[2]) == 2 && count_nb_format(data[2]) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE SPHERE INFORMATIONS */
int	parse_sphere_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_sphere_format(str, type) == 1)
	{
		mini_rt->sp->origin_coord->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->sp->origin_coord->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->sp->origin_coord->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->sp->diam = ft_atof(data[1]);
		mini_rt->sp->color->r = ft_atof(trunc_code(data[2], 0));
		mini_rt->sp->color->g = ft_atof(trunc_code(data[2], find_next_code(data[2]) + 1));
		mini_rt->sp->color->b = ft_atof(trunc_code(data[2], (ft_strlen(trunc_code(data[2], 0)) + ft_strlen(trunc_code(data[2], find_next_code(data[2]) + 1)) + 2))); 
		ft_putstr("SPHERE DONE\n");
		return (1);
	}
	return (0);
}