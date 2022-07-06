/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:56:39 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:56:39 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_atoi_color(char *str)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				res = ((res * 10) + (str[i] - '0'));
				if (res > 255 || res < 0)
					ft_error(DATA_ERROR);
				i++;
			}
		}
		else
			ft_error(DATA_ERROR);
	}
	return (res);
}
