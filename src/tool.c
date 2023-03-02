/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:21:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/02 17:33:17 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_fdf(t_data *data, const char *arg)
{
	data->x_max = 0;
	data->y_max = 0;
	ft_import_map(arg, data);
	data->mid_height = HEIGHT / 2;
	data->mid_length = LENGTH / 2;
	data->a = RAD * 45;
	data->b = RAD * -35;
	data->c = RAD * 30;
	data->intensity = 1;
	data->zoom = 2000 / data->x_max;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "Fdf");
	if (!data->mlx_win)
		ft_exit(data);
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
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(1);
}
