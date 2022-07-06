/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:24 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:24 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	load_image(t_img *img, void *mlx_ptr, char *path)
{
	if (!ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4))
		img->img = mlx_xpm_file_to_image(mlx_ptr, path,
				&img->img_width, &img->img_height);
	if (!img->img)
	{
		error_message("Error : ");
		error_message(path);
		error_message(" : No such image or format error\n");
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_l, &img->endian);
}

void	save_image(t_data *data, int **text, char *path, t_img *img)
{
	int		x;
	int		y;

	y = 0;
	load_image(img, data->mlx, path);
	*text = malloc(sizeof(int) * TXTR_H * TXTR_W);
	while (y < img->img_height - 1)
	{
		x = 0;
		while (x < img->img_width)
		{
			(*text)[img->img_width * y + x] = img->addr[img->img_width * y + x];
			x++;
		}
		y++;
	}
}
