/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:10:13 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 09:28:40 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	return (res);
}
