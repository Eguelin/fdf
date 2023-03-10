/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilienguelin <emilienguelin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:53:28 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/06 19:09:09 by emilienguel      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line(t_data *data, t_coord coord1, t_coord coord2);
static int		ft_in_screen(t_coord coord1, t_coord coord2);
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
	data->img.img = mlx_new_image(data->mlx, LENGTH, HEIGHT);
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
	ft_rgb(data);
	return (0);
}

static void	ft_draw_line(t_data *data, t_coord coord1, t_coord coord2)
{
	float	dx;
	float	dy;
	float	dmax;
	int		i;

	if (ft_in_screen(coord1, coord2))
		return ;
	i = 0;
	dx = coord2.x_bis - coord1.x_bis;
	dy = coord2.y_bis - coord1.y_bis;
	dmax = highest(dx, dy);
	dx /= dmax;
	dy /= dmax;
	while (dmax > i)
	{
		if (!(coord1.x_bis < 0 || coord1.x_bis > LENGTH || \
		coord1.y_bis < 0 || coord1.y_bis > HEIGHT))
			ft_mlx_pixel_put(&data->img, coord1.x_bis, coord1.y_bis, \
			ft_gradient_color(&coord1.color, &coord2.color, dmax, i));
		coord1.x_bis += dx;
		coord1.y_bis += dy;
		i++;
	}
}

static int	ft_in_screen(t_coord coord1, t_coord coord2)
{
	if ((coord1.y_bis < 0 && coord2.y_bis < 0) || \
	(coord1.y_bis > HEIGHT && coord2.y_bis > HEIGHT))
		return (1);
	else if ((coord1.x_bis < 0 && coord2.x_bis < 0) || \
	(coord1.x_bis > LENGTH && coord2.x_bis > LENGTH))
		return (1);
	return (0);
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
