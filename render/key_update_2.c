/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:12 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:12 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	move_to_left(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x - d->rc->plane_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y - d->rc->plane_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x -= d->rc->plane_x * d->rc->move_speed;
		d->rc->pos_y -= d->rc->plane_y * d->rc->move_speed;
	}
}

void	key_update(t_data *d)
{
	if (d->key[W])
		move_straight(d);
	if (d->key[S])
		move_back(d);
	if (d->key[D])
		move_to_right(d);
	if (d->key[A])
		move_to_left(d);
	if (d->key_r)
		screen_right(d);
	if (d->key_l)
		screen_left(d);
}
