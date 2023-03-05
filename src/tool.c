/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilien <emilien@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:21:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/04 19:21:53 by emilien          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_fdf(t_data *data, const char *path)
{
	data->x_max = 0;
	data->y_max = 0;
	data->z_max = INT32_MIN;
	data->z_min = INT32_MAX;
	ft_import_map(path, data);
	ft_isometric(data);
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
