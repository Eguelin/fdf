/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/23 14:55:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	matx(t_data data, int i)
{
	return (sin(AgW) * data.map[i].x  - sin(AgW) * data.map[i].y);
}

float	maty(t_data data, int i)
{
	return (-sin(AgW) * sin(AgA) * data.map[i].x - cos(AgW) * sin(AgA) * data.map[i].y + cos(AgA) * data.map[i].z);
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.x = 0;
	data.y = 0;
	(void)argc;
	ft_import_map(argv[1], &data);
	printf("x = %d y = %d \n", data.x, data.y);
	while (i < data.x * data.y)
	{
		printf("%d. x = %f y = %f z = %f\n", i, data.map[i].x, \
		data.map[i].y, data.map[i].z);
		i++;
	}
	i = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	data.img.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_length, &data.img.endian);
	while (i < data.x * data.y)
	{
		my_mlx_pixel_put(&data.img, matx(data, i) * 40 + 960, maty(data, i) * 40 * -1 + 540, 0x00FFFFFF);
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	free(data.map);
	return (0);
}
