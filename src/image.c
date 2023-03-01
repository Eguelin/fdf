/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:53:28 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/01 16:57:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line(t_data *data, t_coord coord1, t_coord coord2);
static float	highest(float dx, float dy);
static void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);

int	ft_image(t_data *data)
{
	int		i;
	float	x_max;
	float	y_max;

	i = 0;
	x_max = -0.5 + (float)data->x_max / 2;
	y_max = -0.5 + (float)data->y_max / 2;
	data->img.img = mlx_new_image(data->mlx, data->length, data->height);
	if (!data->img.img)
		ft_exit(data);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	while (i < data->x_max * data->y_max)
	{
		if (data->map[i].x < x_max && data->map[i].y == data->map[i + 1].y)
			ft_draw_line(data, data->map[i], data->map[i + 1]);
		if (data->map[i].y < y_max)
			ft_draw_line(data, data->map[i], data->map[i + data->x_max]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}

static void	ft_draw_line(t_data *data, t_coord coord1, t_coord coord2)
{
	float	dx;
	float	dy;
	float	dmax;

	if ((coord1.y_bis < 0 && coord2.y_bis < 0) || \
	(coord1.y_bis > data->height && coord2.y_bis > data->height))
		return ;
	else if ((coord1.x_bis < 0 && coord2.x_bis < 0) || \
	(coord1.x_bis > data->length && coord2.x_bis > data->length))
		return ;
	dx = coord2.x_bis - coord1.x_bis;
	dy = coord2.y_bis - coord1.y_bis;
	dmax = highest(dx, dy);
	dx /= dmax;
	dy /= dmax;
	while (dmax > 0)
	{
		if (!(coord1.x_bis < 0 || coord1.x_bis > data->length || \
		coord1.y_bis < 0 || coord1.y_bis > data->height))
			ft_mlx_pixel_put(&data->img, coord1.x_bis, coord1.y_bis, \
			0x00FFFFFF);
		coord1.x_bis += dx;
		coord1.y_bis += dy;
		dmax--;
	}
}

static float	highest(float dx, float dy)
{
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	if (dx > dy)
		return (dx);
	return (dy);
}

static void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
