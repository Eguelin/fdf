/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:32:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/26 13:47:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotation_x(t_data *data, float rotation[3][3]);
static void	ft_rotation_y(t_data *data, float rotation[3][3]);
static void	ft_rotation_z(t_data *data, float rotation[3][3]);
static void	ft_matrix_calculation(float *x, float *y, float *z, float mr[3][3]);

void	ft_rotation_matrix(t_data *data)
{
	float	rx[3][3];
	float	ry[3][3];
	float	rz[3][3];
	int		i;

	i = 0;
	ft_rotation_x(data, rx);
	ft_rotation_y(data, ry);
	ft_rotation_z(data, rz);
	while (i < data->x_max * data->y_max)
	{
		ft_matrix_calculation(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, rx);
		ft_matrix_calculation(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, ry);
		ft_matrix_calculation(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, rz);
		data->map[i].x_bis = data->map[i].x_bis + (float)data->length / 2;
		data->map[i].y_bis = data->map[i].y_bis + (float)data->height / 2;
		i++;
	}
}

static void	ft_rotation_x(t_data *data, float rotation[3][3])
{
	rotation[0][0] = 1;
	rotation[0][1] = 0;
	rotation[0][2] = 0;
	rotation[1][0] = 0;
	rotation[1][1] = cos(data->a);
	rotation[1][2] = -sin(data->a);
	rotation[2][0] = 0;
	rotation[2][1] = sin(data->a);
	rotation[2][2] = cos(data->a);
}

static void	ft_rotation_y(t_data *data, float rotation[3][3])
{
	rotation[0][0] = cos(data->b);
	rotation[0][1] = 0;
	rotation[0][2] = sin(data->b);
	rotation[1][0] = 0;
	rotation[1][1] = 1;
	rotation[1][2] = 0;
	rotation[2][0] = -sin(data->b);
	rotation[2][1] = 0;
	rotation[2][2] = cos(data->b);
}

static void	ft_rotation_z(t_data *data, float rotation[3][3])
{
	rotation[0][0] = cos(data->c);
	rotation[0][1] = -sin(data->c);
	rotation[0][2] = 0;
	rotation[1][0] = sin(data->c);
	rotation[1][1] = cos(data->c);
	rotation[1][2] = 0;
	rotation[2][0] = 0;
	rotation[2][1] = 0;
	rotation[2][2] = 1;
}

static void	ft_matrix_calculation(float *x, float *y, float *z, float mr[3][3])
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
