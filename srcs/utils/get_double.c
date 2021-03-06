/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:23:31 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:07:49 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*get_double(char *str, int i)
{
	char	*ratio_str;

	ratio_str = ft_calloc(1, sizeof(char));
	if (!(ratio_str))
		return (NULL);
	while (str[i])
	{
		if ((ft_isdigit(str[i]) || str[i] == '.') && str[i])
		{
			ratio_str = str_add_char(ratio_str, str[i]);
			if (!(ratio_str))
				return (NULL);
			else if (ft_isdigit(str[i]) && (str[i + 1] == ' '
					|| str[i + 1] == '	'))
				break ;
		}
		i++;
	}
	return (ratio_str);
}
