/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:57:50 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 22:57:50 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	button_press(int key, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (key == ESC)
		exit(0);
	if (key == W || key == S || key == A || key == D || key == LEFT
		|| key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 1;
		else if (key == RIGHT)
			data->key_r = 1;
		else
			data->key[key] = 1;
	}
	return (key);
}

int	button_execution(int key, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (key == ESC)
	{
		write(1, "Good bye!", 10);
		exit(0);
	}
	if (key == W || key == S || key == A
		|| key == D || key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 0;
		else if (key == RIGHT)
			data->key_r = 0;
		else
			data->key[key] = 0;
	}
	return (key);
}
