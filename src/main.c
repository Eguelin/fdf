/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/27 18:44:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_image(t_data *data);

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(0);
}

/*key = 45
key = 61
key = 65453
key = 65451*/

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close(data);
	else if (keycode == 113)
		data->c -= RAD * 1;
	else if (keycode == 101)
		data->c += RAD * 1;
	else if (keycode == 119)
		data->a += RAD * 1;
	else if (keycode == 115)
		data->a -= RAD * 1;
	else if (keycode == 97)
		data->b -= RAD * 1;
	else if (keycode == 100)
		data->b += RAD * 1;
	else if (keycode == 100)
		data->b += RAD * 1;
	else if (keycode == 100)
		data->b += RAD * 1;
	ft_image(data);
	printf("key = %d\n", keycode);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(1);
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

void	ft_line2(t_data *data, t_coord coord1, t_coord coord2)
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
		{
			ft_line2(data, coord2, coord1);
			break ;
		}
		ft_mlx_pixel_put(&data->img, coord1.x_bis, coord1.y_bis, 0x00FFFFFF);
		coord1.x_bis += dx;
		coord1.y_bis += dy;
		dmax--;
	}
}

void	ft_image(t_data *data)
{
	int		i;
	int		i_max;
	float	x_max;
	float	y_max;

	i = 0;
	i_max = data->x_max * data->y_max;
	x_max = -0.5 + (float)data->x_max / 2;
	y_max = -0.5 + (float)data->y_max / 2;
	data->img.img = mlx_new_image(data->mlx, data->length, data->height);
	if (!data->img.img)
		ft_exit(data);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	ft_rotation_matrix(data);
	while (i < i_max)
	{
		if (data->map[i].x < x_max && data->map[i].y == data->map[i + 1].y)
			ft_line(data, data->map[i], data->map[i + 1]);
		if (data->map[i].y < y_max)
			ft_line(data, data->map[i], data->map[i + data->x_max]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	data.x_max = 0;
	data.y_max = 0;
	data.height = 2000;
	data.length = 3000;
	data.zoom = 5;
	data.a = RAD * 45;
	data.b = RAD * -35;
	data.c = RAD * 30;
	(void)argc;
	ft_import_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(1);
	data.mlx_win = mlx_new_window(data.mlx, data.length, data.height, "Fdf");
	if (!data.mlx_win)
		ft_exit(&data);
	ft_image(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
