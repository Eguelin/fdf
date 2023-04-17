/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:21:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 13:14:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_fdf(t_data *data, const char *path)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->x_max = 0;
	data->y_max = 0;
	data->path = path;
	ft_import_map(data->path, data);
	data->mid_height = HEIGHT * 0.6;
	data->mid_length = LENGTH * 0.5;
	data->zoom = 1500 / data->x_max;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data);
	data->mlx_win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "Fdf");
	if (!data->mlx_win)
		ft_exit(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	return (0);
}

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
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(1);
}
