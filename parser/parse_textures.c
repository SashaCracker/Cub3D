/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:57:21 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:57:21 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_texs(char *str, int i)
{
	if (!str[i])
		ft_error(DATA_ERROR);
	else
	{
		while (str[i])
		{
			if (str[i] == '.' && str[i + 1] == '/')
				break ;
			if (str[i] == ' ')
				i++;
			else
				ft_error(DATA_ERROR);
		}
	}
}

static char	*get_str_texs(char *str, int *i)
{
	int		j;
	int		len;
	char	*tmp;

	j = *i;
	len = (int)ft_strlen(str);
	while (str[++j])
	{
		if (!ft_isalnum(str[j]) && str[j] != '_'
			&& str[j] != '/' && str[j] != '.')
			ft_error(DATA_ERROR);
		else if (!ft_isalnum(str[len - 1]) && str[len - 1] != '/')
			ft_error(DATA_ERROR);
	}
	tmp = ft_substr(str, *i, len - (*i));
	*i = j;
	str = tmp;
	return (str);
}

void	get_textures(int *i, char *line, t_parser *data, char *flag)
{
	(*i) += 2;
	check_texs(line, *i);
	while (line[*i])
	{
		if (line[*i] == ' ')
			(*i)++;
		else if (line[*i] == '.' && line[(*i) + 1] == '/')
		{
			if (!ft_strncmp(flag, "NO", 3) && !data->paths->no)
				data->paths->no = get_str_texs(line, i);
			else if (!ft_strncmp(flag, "SO", 3) && !data->paths->so)
				data->paths->so = get_str_texs(line, i);
			else if (!ft_strncmp(flag, "WE", 3) && !data->paths->we)
				data->paths->we = get_str_texs(line, i);
			else if (!ft_strncmp(flag, "EA", 3) && !data->paths->ea)
				data->paths->ea = get_str_texs(line, i);
			break ;
		}
		else
			ft_error(DATA_ERROR);
	}
}
