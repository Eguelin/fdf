/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:32:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/02 15:10:41 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_matrix_rotation_x(t_data *data, float rotation[3][3]);
static void	ft_matrix_rotation_y(t_data *data, float rotation[3][3]);
static void	ft_matrix_rotation_z(t_data *data, float rotation[3][3]);
static void	ft_matrix_calcul(float *x, float *y, float *z, float mr[3][3]);

void	ft_projection(t_data *data)
{
	float	matrix_x[3][3];
	float	matrix_y[3][3];
	float	matrix_z[3][3];
	int		i;

	i = data->x_max * data->y_max - 1;
	ft_matrix_rotation_x(data, matrix_x);
	ft_matrix_rotation_y(data, matrix_y);
	ft_matrix_rotation_z(data, matrix_z);
	while (i >= 0)
	{
		data->map[i].x_bis = data->map[i].x;
		data->map[i].y_bis = data->map[i].y;
		data->map[i].z_bis = data->map[i].z * data->intensity;
		ft_matrix_calcul(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, matrix_x);
		ft_matrix_calcul(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, matrix_y);
		ft_matrix_calcul(&data->map[i].x_bis, &data->map[i].y_bis, \
		&data->map[i].z_bis, matrix_z);
		data->map[i].x_bis = data->map[i].x_bis * data->zoom + data->mid_length;
		data->map[i].y_bis = data->map[i].y_bis * data->zoom + data->mid_height;
		i--;
	}
}

static void	ft_matrix_rotation_x(t_data *data, float matrix[3][3])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(data->a);
	matrix[1][2] = -sin(data->a);
	matrix[2][0] = 0;
	matrix[2][1] = sin(data->a);
	matrix[2][2] = cos(data->a);
}

static void	ft_matrix_rotation_y(t_data *data, float matrix[3][3])
{
	matrix[0][0] = cos(data->b);
	matrix[0][1] = 0;
	matrix[0][2] = sin(data->b);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(data->b);
	matrix[2][1] = 0;
	matrix[2][2] = cos(data->b);
}

static void	ft_matrix_rotation_z(t_data *data, float matrix[3][3])
{
	matrix[0][0] = cos(data->c);
	matrix[0][1] = -sin(data->c);
	matrix[0][2] = 0;
	matrix[1][0] = sin(data->c);
	matrix[1][1] = cos(data->c);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

static void	ft_matrix_calcul(float *x, float *y, float *z, float matrix[3][3])
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;

	tmp_x = *x * matrix[0][0] + *y * matrix[0][1] + *z * matrix[0][2];
	tmp_y = *x * matrix[1][0] + *y * matrix[1][1] + *z * matrix[1][2];
	tmp_z = *x * matrix[2][0] + *y * matrix[2][1] + *z * matrix[2][2];
	*x = tmp_x;
	*y = tmp_y;
	*z = tmp_z;
}
