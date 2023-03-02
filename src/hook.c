/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/02 17:30:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_hook2(int keycode, t_data *data);

int	key_hook(int keycode, t_data *data)
{
	float	one_degree;

	one_degree = 0.017453293;
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == Q)
		data->c -= one_degree;
	else if (keycode == E)
		data->c += one_degree;
	else if (keycode == W)
		data->a += one_degree;
	else if (keycode == S)
		data->a -= one_degree;
	else if (keycode == A)
		data->b -= one_degree;
	else if (keycode == D)
		data->b += one_degree;
	else
		key_hook2(keycode, data);
	ft_projection(data);
	return (0);
}

static void	key_hook2(int keycode, t_data *data)
{
	if (keycode == EQUALS_PLUS && data->zoom < 19000)
		data->zoom *= 1.1;
	else if (keycode == DASH_UNDERSCORE && data->zoom > 0.05)
		data->zoom *= 0.9;
	else if (keycode == UP_ARROW && data->mid_height > -2000000)
		data->mid_height -= data->zoom / 10;
	else if (keycode == DOWN_ARROW && data->mid_height < 2000000)
		data->mid_height += data->zoom / 10;
	else if (keycode == LEFT_ARROW && data->mid_height > -2000000)
		data->mid_length -= data->zoom / 10;
	else if (keycode == RIGHT_ARROW && data->mid_height < 2000000)
		data->mid_length += data->zoom / 10;
	else if (keycode == CLOSE_BRACKET && data->intensity == 0)
		data->intensity = 0.001;
	else if (keycode == CLOSE_BRACKET && data->intensity < 100)
		data->intensity *= 1.1;
	else if (keycode == OPEN_BRACKET && data->intensity > 0.001)
		data->intensity *= 0.9;
	else if (keycode == OPEN_BRACKET && data->intensity < 0.001)
		data->intensity = 0;
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4 && data->zoom < 19000)
		data->zoom *= 1.1;
	else if (button == 5 && data->zoom > 0.05)
		data->zoom *= 0.9;
	else if (button == 1)
	{
		data->mid_length = x;
		data->mid_height = y;
	}
	else if (button == 2)
	{
		data->mid_height = HEIGHT / 2;
		data->mid_length = LENGTH / 2;
	}
	ft_projection(data);
	return (0);
}
