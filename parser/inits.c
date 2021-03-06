/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:57:00 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:57:00 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	color_init(t_rgb **rgb)
{
	*rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		ft_error(MALLOC_ERROR);
	(*rgb)->r = -1;
	(*rgb)->g = -1;
	(*rgb)->b = -1;
}
