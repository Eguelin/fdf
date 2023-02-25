/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/25 12:50:26 by eguelin          ###   ########lyon.fr   */
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

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.x_max = 0;
	data.y_max = 0;
	data.a = RAD * 30;
	data.b = RAD * -30;
	data.c = RAD * 30;
	(void)argc;
	ft_import_map(argv[1], &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 3840, 2160, "Hello world!");
	data.img.img = mlx_new_image(data.mlx, 3840, 2160);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_length, &data.img.endian);
	ft_rotation_matrix(&data);
	while (i < data.x_max * data.y_max)
	{
		if (data.map[i].x_bis * 10 + 1920 >= 0 && data.map[i].x_bis * 10 + 1920 <= 3840 && data.map[i].y_bis * 10 + 1080 >= 0 && data.map[i].y_bis * 10 + 1080 <= 2160)
			ft_mlx_pixel_put(&data.img, data.map[i].x_bis * 10 + 1920, data.map[i].y_bis * 10 + 1080, (0x00FFFFFF) - (0x00FF00FF * data.map[i].z));
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	free(data.map);
	return (0);
}
