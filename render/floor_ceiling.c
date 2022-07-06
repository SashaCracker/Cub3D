/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:57:55 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:57:55 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	floor_ceiling(t_data *d)
{
	int	y;
	int	x;
	int	ceiling;
	int	floor;

	floor = create_color(
			d->parser->colors->floor->r,
			d->parser->colors->floor->g,
			d->parser->colors->floor->b);
	ceiling = create_color(
			d->parser->colors->cell->r,
			d->parser->colors->cell->g,
			d->parser->colors->cell->b);
	y = WIN_Y / 2 - 1;
	while (y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			d->buff[WIN_Y - y - 1][x] = ceiling;
			d->buff[y][x] = floor;
		}
		y++;
	}
}
