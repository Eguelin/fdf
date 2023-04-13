/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:32:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/13 18:03:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_matrix_rotation_x(t_data *data, double matrix[3][3]);
static void	ft_matrix_rotation_y(t_data *data, double matrix[3][3]);
static void	ft_matrix_rotation_z(t_data *data, double matrix[3][3]);
static void	ft_matrix_calcul(double *x, double *y, double *z, double mr[3][3]);

void	ft_projection(t_data *data)
{
	double	matrix_x[3][3];
	double	matrix_y[3][3];
	double	matrix_z[3][3];
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

static void	ft_matrix_rotation_x(t_data *data, double matrix[3][3])
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

static void	ft_matrix_rotation_y(t_data *data, double matrix[3][3])
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

static void	ft_matrix_rotation_z(t_data *data, double matrix[3][3])
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
