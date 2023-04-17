/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:21:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 12:54:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_header(t_data *data);

void	ft_init_fdf(t_data *data, const char *path)
{
	data->x_max = 0;
	data->y_max = 0;
	data->z_max = INT_MIN;
	data->z_min = INT_MAX;
	data->rgb_on_off = 0;
	data->path = path;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->header.mlx_win = NULL;
	ft_import_map(data->path, data);
	ft_isometric(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data);
	data->mlx_win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "Fdf");
	if (!data->mlx_win)
		ft_exit(data);
	ft_header(data);
}

static void	ft_header(t_data *data)
{
	int	w;
	int	h;

	data->header.mlx_win = mlx_new_window(data->mlx, 540, 1920, "Header");
	if (!data->header.mlx_win)
		ft_exit(data);
	data->header.ptr = mlx_xpm_file_to_image(data->mlx, "image/Header_fdf.xpm", \
	&w, &h);
	if (!data->header.ptr)
		ft_exit(data);
	mlx_put_image_to_window(data->mlx, data->header.mlx_win, data->header.ptr, \
	0, 0);
	mlx_destroy_image(data->mlx, data->header.ptr);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->header.mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(0);
}

int	ft_exit(t_data *data)
{
	if (data->header.mlx_win)
		mlx_destroy_window(data->mlx, data->header.mlx_win);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(1);
}
