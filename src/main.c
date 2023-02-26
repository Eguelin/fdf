/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/26 14:04:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_exit(t_data *data, int fd, int i)
{
	free(data->map);
	mlx_destroy_image(data->mlx ,data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (fd)
		close(fd);
	exit(i);
}

float	highest(float dx, float dy)
{
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	if (dx > dy)
		return (dx);
	return (dy);
}

void	ft_line(t_data *data, t_coord coord1, t_coord coord2)
{
	float	dx;
	float	dy;
	float	dmax;

	dx = coord2.x_bis - coord1.x_bis;
	dy = coord2.y_bis - coord1.y_bis;
	dmax = highest(dx, dy);
	dx /= dmax;
	dy /= dmax;
	while (dmax > 0)
	{
		if (coord1.x_bis < 0 || coord1.x_bis > data->length || \
		coord1.y_bis < 0 || coord1.y_bis > data->height)
			break ;
		ft_mlx_pixel_put(&data->img, coord1.x_bis, coord1.y_bis, 0x00FFFFFF);
		coord1.x_bis += dx;
		coord1.y_bis += dy;
		dmax--;
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.x_max = 0;
	data.y_max = 0;
	data.height = 2160;
	data.length = 3840;
	data.zoom = 8;
	data.a = RAD * 45;
	data.b = RAD * -35;
	data.c = RAD * 30;
	(void)argc;
	ft_import_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(0);
	data.mlx_win = mlx_new_window(data.mlx, 3840, 2160, "Fdf");
	if (!data.mlx_win)
		exit(0);
	data.img.img = mlx_new_image(data.mlx, 3840, 2160);
	if (!data.img.img)
		exit(0);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_length, &data.img.endian);
	ft_rotation_matrix(&data);
	while (i < data.x_max * data.y_max)
	{
		if (data.map[i].x < -0.5 + (float)data.x_max / 2 && data.map[i].y == data.map[i + 1].y)
			ft_line(&data, data.map[i], data.map[i + 1]);
		if (data.map[i].y < -0.5 + (float)data.y_max /2)
			ft_line(&data, data.map[i], data.map[i + data.x_max]);
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	ft_exit(&data, 0, 0);
	return (0);
}
