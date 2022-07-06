/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:35 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:35 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libs/include.h"
# include "../parser/cub3D.h"
# include "../includes/structures.h"

void	render_init(t_data *data);
int		render(t_data *data);	
void	load_textures(t_data *data);
void	player_position(t_data *d);
int		create_color(int r, int g, int b);
int		button_press(int key, void *d);
int		action(t_data *data);
void	floor_ceiling(t_data *data);
void	walls(t_data *data);
void	textures(t_data *data);
void	key_update(t_data *data);
int		button_execution(int key, void *d);
void	screen_right(t_data *d);
void	screen_left(t_data *d);
void	error_message(char *message);
void	save_image(t_data *data, int **text, char *path, t_img *img);
void	load_image(t_img *img, void *mlx_ptr, char *path);
void	draw_textures(t_data *d, int x);
void	wall_x(t_data *d);
void	choose_textures_color(t_data *d);
void	map_convertation(t_data *d);
void	draw_buff(t_data *data);
void	move_straight(t_data *d);
void	move_back(t_data *d);
void	move_to_right(t_data *d);
int		key_hook(t_data *data);

#endif
