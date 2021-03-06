/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:01 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:01 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	screen_right(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_plane_x = d->rc->plane_x;
	old_dir_x = d->rc->dir_x;
	d->rc->dir_x = d->rc->dir_x * cos(-d->rc->rot_speed)
		- d->rc->dir_y * sin(-d->rc->rot_speed);
	d->rc->dir_y = old_dir_x * sin(-d->rc->rot_speed)
		+ d->rc->dir_y * cos(-d->rc->rot_speed);
	d->rc->plane_x = d->rc->plane_x * cos(-d->rc->rot_speed)
		- d->rc->plane_y * sin(-d->rc->rot_speed);
	d->rc->plane_y = old_plane_x * sin(-d->rc->rot_speed)
		+ d->rc->plane_y * cos(-d->rc->rot_speed);
}

void	screen_left(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_plane_x = d->rc->plane_x;
	old_dir_x = d->rc->dir_x;
	d->rc->dir_x = d->rc->dir_x * cos(d->rc->rot_speed)
		- d->rc->dir_y * sin(d->rc->rot_speed);
	d->rc->dir_y = old_dir_x * sin(d->rc->rot_speed)
		+ d->rc->dir_y * cos(d->rc->rot_speed);
	d->rc->plane_x = d->rc->plane_x * cos(d->rc->rot_speed)
		- d->rc->plane_y * sin(d->rc->rot_speed);
	d->rc->plane_y = old_plane_x * sin(d->rc->rot_speed)
		+ d->rc->plane_y * cos(d->rc->rot_speed);
}

void	move_straight(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x + d->rc->dir_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y + d->rc->dir_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x += d->rc->dir_x * d->rc->move_speed;
		d->rc->pos_y += d->rc->dir_y * d->rc->move_speed;
	}
}

void	move_back(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x - d->rc->dir_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y - d->rc->dir_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x -= d->rc->dir_x * d->rc->move_speed;
		d->rc->pos_y -= d->rc->dir_y * d->rc->move_speed;
	}
}

void	move_to_right(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x + d->rc->plane_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y + d->rc->plane_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x += d->rc->plane_x * d->rc->move_speed;
		d->rc->pos_y += d->rc->plane_y * d->rc->move_speed;
	}
}
