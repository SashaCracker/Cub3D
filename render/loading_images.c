/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:58:18 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:18 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	load_textures(t_data *d)
{
	t_img	img;

	save_image(d, &d->textures[0], d->parser->paths->no, &img);
	save_image(d, &d->textures[1], d->parser->paths->so, &img);
	save_image(d, &d->textures[2], d->parser->paths->ea, &img);
	save_image(d, &d->textures[3], d->parser->paths->we, &img);
}
