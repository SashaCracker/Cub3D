/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:53:36 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:53:36 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/include.h"
# include "../includes/structures.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line, int ret);
int		ft_atoi_color(char *str);
void	ft_error(int key);
void	color_init(t_rgb **rgb);
int		check_params(t_parser *data, char **file);
int		if_all(t_parser *data);
void	parse(t_parser *data, char *argv);
void	parse_file(t_parser *data, char **file, int *i, int *j);
int		find_map(int *i, char **file, t_parser *data);
char	**check_map(char **map, t_parser *data, int size, int len);
int		check(char *filename);
int		check_walls(char *str, int i);
int		check_str(char *str, int j, t_parser *data);
void	get_char(char c, t_parser *data, int x, int y);
void	get_textures(int *i, char *line, t_parser *data, char *flag);
t_rgb	*make_color(char **arr);
void	free_map(char **map);
void	if_space(char *str, int *i);
void	get_color(int *i, char *line, t_parser *data, char flag);

#endif
