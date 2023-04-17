/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:37:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 13:05:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_isometric(t_data *data)
{
	data->mid_height = HEIGHT * 0.5;
	data->mid_length = LENGTH * 0.5;
	data->a = PI * 0.25;
	data->b = PI / 180 * -35;
	data->c = PI / 6;
	data->intensity = 1;
	data->zoom = 2200 / data->x_max;
}

void	ft_parallel(t_data *data)
{
	data->mid_height = HEIGHT * 0.5;
	data->mid_length = LENGTH * 0.5;
	data->a = PI * 0.25;
	data->b = 0;
	data->c = 0;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}

void	ft_front(t_data *data)
{
	data->mid_height = HEIGHT * 0.5;
	data->mid_length = LENGTH * 0.5;
	data->a = PI * 0.5;
	data->b = 0;
	data->c = 0;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}

void	ft_above(t_data *data)
{
	data->mid_height = HEIGHT * 0.5;
	data->mid_length = LENGTH * 0.5;
	data->a = 0;
	data->b = 0;
	data->c = 0;
	data->intensity = 0.1;
	data->zoom = 2200 / data->x_max;
}
