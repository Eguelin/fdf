/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/01 19:56:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(1);
}

/*key = 45
key = 61
key = 65453
key = 65451*/

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
	else if (keycode == EQUALS_PLUS && data->zoom < 19000)
		data->zoom *= 1.1;
	else if (keycode == DASH_UNDERSCORE && data->zoom > 0.05)
		data->zoom *= 0.9;
	else if (keycode == UP_ARROW && data->mid_height > -20000000)
		data->mid_height -= data->zoom / 10;
	else if (keycode == DOWN_ARROW && data->mid_height < 20000000)
		data->mid_height += data->zoom / 10;
	else if (keycode == LEFT_ARROW && data->mid_height > -20000000)
		data->mid_length -= data->zoom / 10;
	else if (keycode == RIGHT_ARROW && data->mid_height < 20000000)
		data->mid_length += data->zoom / 10;
	else if (keycode == CLOSE_BRACKET && data->intensity == 0)
		data->intensity = 0.001;
	else if (keycode == CLOSE_BRACKET && data->intensity < 100)
		data->intensity *= 1.1;
	else if (keycode == OPEN_BRACKET && data->intensity > 0.001)
		data->intensity *= 0.9;
	else if (keycode == OPEN_BRACKET && data->intensity < 0.001)
		data->intensity = 0;
	ft_projection(data);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	(void)argc;
	data.x_max = 0;
	data.y_max = 0;
	data.height = 2058;
	data.length = 3840;
	data.mid_height = data.height / 2;
	data.mid_length = data.length / 2;
	data.a = RAD * 45;
	data.b = RAD * -35;
	data.c = RAD * 30;
	data.intensity = 1;
	ft_import_map(argv[1], &data);
	data.zoom = (501 - data.x_max) / 0.249;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, data.length, data.height, "Fdf");
	if (!data.mlx_win)
		ft_exit(&data);
	ft_projection(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_loop_hook(data.mlx, ft_image, &data);
	mlx_loop(data.mlx);
	return (0);
}
