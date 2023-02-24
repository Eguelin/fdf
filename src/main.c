/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/24 17:40:23 by eguelin          ###   ########lyon.fr   */
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

void matrix_calculation(float *x, float *y, float *z, float	mr[3][3])
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;

	tmp_x = *x * mr[0][0] + *y * mr[0][1] + *z * mr[0][2];
	tmp_y = *x * mr[1][0] + *y * mr[1][1] + *z * mr[1][2];
	tmp_z = *x * mr[2][0] + *y * mr[2][1] + *z * mr[2][2];
	*x = tmp_x;
	*y = tmp_y;
	*z = tmp_z;
}

void rotation_matrix(t_data *data)
{
	float	rx[3][3] = {{1, 0, 0}, {0, cos(data->a), -sin(data->a)}, {0, sin(data->a), cos(data->a)}};
	float	ry[3][3] = {{cos(data->b), 0, sin(data->b)}, {0, 1, 0}, {-sin(data->b), 0, cos(data->b)}};
	float	rz[3][3] = {{cos(data->c), -sin(data->c), 0}, {sin(data->c), cos(data->c), 0}, {0, 0, 1}};
	int		i;

	i = 0;
	while (i < data->x * data->y)
	{
		matrix_calculation(&data->map[i].x, &data->map[i].y, &data->map[i].z, rx);
		matrix_calculation(&data->map[i].x, &data->map[i].y, &data->map[i].z, ry);
		matrix_calculation(&data->map[i].x, &data->map[i].y, &data->map[i].z, rz);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.x = 0;
	data.y = 0;
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
	rotation_matrix(&data);
	while (i < data.x * data.y)
	{
		if (data.map[i].x * 10 + 1920 >= 0 && data.map[i].x * 10 + 1920 <= 3840 && data.map[i].y * 10 + 1080 >= 0 && data.map[i].y * 10 + 1080 <= 2160)
			ft_mlx_pixel_put(&data.img, data.map[i].x * 10 + 1920, data.map[i].y * 10 + 1080, 0x00FFFFFF);
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	free(data.map);
	return (0);
}
