/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:30 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:30 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	sides(t_data *d)
{
	if (d->parser->pos == 'W')
	{
		d->rc->plane_x = -0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = -1;
	}
	if (d->parser->pos == 'E')
	{
		d->rc->plane_x = 0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = 1;
	}
}

void	player_position(t_data *d)
{
	d->rc->pos_x = (double)d->parser->pos_y + 0.5;
	d->rc->pos_y = (double)d->parser->pos_x + 0.5;
	if (d->parser->pos == 'N')
	{
		d->rc->plane_x = 0.0;
		d->rc->plane_y = 0.66;
		d->rc->dir_x = -1.0;
		d->rc->dir_y = 0.0;
	}
	if (d->parser->pos == 'S')
	{
		d->rc->plane_x = 0;
		d->rc->plane_y = -0.66;
		d->rc->dir_x = 1.0;
		d->rc->dir_y = 0.0;
	}
	sides(d);
}

void	raycasting_init(t_data *d, t_raycaster *rc)
{
	d->rc = rc;
	d->rc->move_speed = 0.05;
	d->rc->rot_speed = 0.02;
	map_convertation(d);
	ft_bzero(d->key, sizeof(512));
}

int	action(t_data *data)
{
	data->curr_time++;
	if (data->curr_time == LONG_MAX)
		data->curr_time = 0;
	floor_ceiling(data);
	walls(data);
	textures(data);
	key_update(data);
	draw_buff(data);
	return (0);
}

int	render(t_data *data)
{
	t_raycaster	rc;

	rc = (t_raycaster){};
	raycasting_init(data, &rc);
	player_position(data);
	load_textures(data);
	mlx_hook(data->mlx_win, KEY_PRESS, (1L << 0), button_press, data);
	mlx_key_hook(data->mlx_win, button_execution, data);
	mlx_hook (data->mlx_win, 17, 0, key_hook, &data);
	mlx_loop_hook(data->mlx, action, data);
	mlx_loop(data->mlx);
	exit(0);
}
