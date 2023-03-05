/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/05 15:59:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_data *data)
{
	data->mid_height = HEIGHT / 2;
	data->mid_length = LENGTH / 2;
	data->a = PI / 4;
	data->b = PI / 180 * -35;
	data->c = PI / 6;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}

void	ft_revers_isometric(t_data *data)
{
	data->mid_height = HEIGHT / 2;
	data->mid_length = LENGTH / 2;
	data->a = PI / 4;
	data->b = -PI / 180 * 35;
	data->c = -5 * PI / 6;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}

void	ft_front(t_data *data)
{
	data->mid_height = HEIGHT / 2;
	data->mid_length = LENGTH / 2;
	data->a = PI / 2;
	data->b = 0;
	data->c = 0;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}

void	ft_above(t_data *data)
{
	data->mid_height = HEIGHT / 2;
	data->mid_length = LENGTH / 2;
	data->a = 0;
	data->b = 0;
	data->c = 0;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}
