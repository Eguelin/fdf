/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:32:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 13:08:39 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_matrix_rotation_x(double matrix[3][3]);
static void	ft_matrix_rotation_y(double matrix[3][3]);
static void	ft_matrix_rotation_z(double matrix[3][3]);
static void	ft_matrix_calcul(double *x, double *y, double *z, double mr[3][3]);

void	ft_projection(t_data *data)
{
	double	matrix_x[3][3];
	double	matrix_y[3][3];
	double	matrix_z[3][3];
	int		i;

	i = data->x_max * data->y_max - 1;
	ft_matrix_rotation_x(matrix_x);
	ft_matrix_rotation_y(matrix_y);
	ft_matrix_rotation_z(matrix_z);
	while (i >= 0)
	{
		data->map[i].x_bis = data->map[i].x;
		data->map[i].y_bis = data->map[i].y;
		data->map[i].z_bis = data->map[i].z;
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

static void	ft_matrix_rotation_x(double matrix[3][3])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(PI * 0.25);
	matrix[1][2] = -sin(PI * 0.25);
	matrix[2][0] = 0;
	matrix[2][1] = sin(PI * 0.25);
	matrix[2][2] = cos(PI * 0.25);
}

static void	ft_matrix_rotation_y(double matrix[3][3])
{
	matrix[0][0] = cos(PI / 180 * -35);
	matrix[0][1] = 0;
	matrix[0][2] = sin(PI / 180 * -35);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(PI / 180 * -35);
	matrix[2][1] = 0;
	matrix[2][2] = cos(PI / 180 * -35);
}

static void	ft_matrix_rotation_z(double matrix[3][3])
{
	matrix[0][0] = cos(PI / 6);
	matrix[0][1] = -sin(PI / 6);
	matrix[0][2] = 0;
	matrix[1][0] = sin(PI / 6);
	matrix[1][1] = cos(PI / 6);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

static void	ft_matrix_calcul(double *x, double *y, double *z, double mr[3][3])
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = *x * mr[0][0] + *y * mr[0][1] + *z * mr[0][2];
	tmp_y = *x * mr[1][0] + *y * mr[1][1] + *z * mr[1][2];
	tmp_z = *x * mr[2][0] + *y * mr[2][1] + *z * mr[2][2];
	*x = tmp_x;
	*y = tmp_y;
	*z = tmp_z;
}
