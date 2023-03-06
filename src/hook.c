/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilienguelin <emilienguelin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/06 19:12:11 by emilienguel      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_hook2(int keycode, t_data *data);
static void	key_hook3(int keycode, t_data *data);
static void	key_hook4(int keycode, t_data *data);

int	key_hook(int keycode, t_data *data)
{
	float	one_degree;

	one_degree = PI / 180;
	if (keycode == KEY_ESC)
		ft_close(data);
	else if (keycode == KEY_Q)
		data->c -= one_degree;
	else if (keycode == KEY_E)
		data->c += one_degree;
	else if (keycode == KEY_W)
		data->a += one_degree;
	else if (keycode == KEY_S)
		data->a -= one_degree;
	else if (keycode == KEY_A)
		data->b -= one_degree;
	else if (keycode == KEY_D)
		data->b += one_degree;
	else
		key_hook2(keycode, data);
	ft_projection(data);
	return (0);
}

static void	key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_EQUALS_PLUS && data->zoom < 19000)
		data->zoom *= 1.1;
	else if (keycode == KEY_DASH_UNDERSCORE && data->zoom > 0.05)
		data->zoom *= 0.9;
	else if (keycode == KEY_UP_ARROW && data->mid_height > -2000000)
		data->mid_height -= data->zoom / 10;
	else if (keycode == KEY_DOWN_ARROW && data->mid_height < 2000000)
		data->mid_height += data->zoom / 10;
	else if (keycode == KEY_LEFT_ARROW && data->mid_height > -2000000)
		data->mid_length -= data->zoom / 10;
	else if (keycode == KEY_RIGHT_ARROW && data->mid_height < 2000000)
		data->mid_length += data->zoom / 10;
	else if (keycode == KEY_CLOSE_BRACKET && data->intensity == 0)
		data->intensity = 0.0001;
	else if (keycode == KEY_CLOSE_BRACKET && data->intensity < 1)
		data->intensity *= 1.1;
	else if (keycode == KEY_OPEN_BRACKET && data->intensity > 0.0001)
		data->intensity *= 0.9;
	else if (keycode == KEY_OPEN_BRACKET && data->intensity < 0.0001)
		data->intensity = 0;
	else
		key_hook3(keycode, data);
}

static void	key_hook3(int keycode, t_data *data)
{
	if (keycode == KEY_1)
		ft_isometric(data);
	else if (keycode == KEY_2)
		ft_revers_isometric(data);
	else if (keycode == KEY_3)
		ft_above(data);
	else if (keycode == KEY_4)
		ft_front(data);
	else if (keycode == KEY_5)
	{
		free(data->map);
		data->x_max = 0;
		data->y_max = 0;
		data->z_max = INT32_MIN;
		data->z_min = INT32_MAX;
		ft_import_map(data->path, data);
	}
	else if (keycode == KEY_6)
		ft_change_color(data, 1);
	else if (keycode == KEY_7)
		ft_change_color(data, 2);
	else
		key_hook4(keycode, data);
}

static void	key_hook4(int keycode, t_data *data)
{
	if (keycode == KEY_0)
	{
		if (data->rgb_on_off)
			data->rgb_on_off = 0;
		else
			data->rgb_on_off = 1;
	}
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->mid_length = x;
		data->mid_height = y;
	}
	else if (button == 2)
		ft_isometric(data);
	else if (button == 3)
	{
		data->mid_height = HEIGHT / 2;
		data->mid_length = LENGTH / 2;
	}
	else if (button == 4 && data->zoom < 19000)
		data->zoom *= 1.1;
	else if (button == 5 && data->zoom > 0.05)
		data->zoom *= 0.9;
	ft_projection(data);
	return (0);
}
