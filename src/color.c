/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilienguelin <emilienguelin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:49 by emilien           #+#    #+#             */
/*   Updated: 2023/03/06 19:03:55 by emilienguel      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_color_palette1(t_data *data, int i);
static void	ft_color_palette2(t_data *data, int i);
static void	ft_color_palette3(t_data *data, int i);

int	ft_gradient_color(t_color *clr1, t_color *clr2, float line, int i)
{
	t_color	clr3;

	if (clr1->code == clr2->code)
		return (clr1->code);
	clr3.trgb.r = clr1->trgb.r + i * (clr2->trgb.r - clr1->trgb.r) / line;
	clr3.trgb.g = clr1->trgb.g + i * (clr2->trgb.g - clr1->trgb.g) / line;
	clr3.trgb.b = clr1->trgb.b + i * (clr2->trgb.b - clr1->trgb.b) / line;
	return (clr3.code);
}

void	ft_change_color(t_data *data, int i)
{
	int	j;
	int	j_max;

	j = 0;
	j_max = data->x_max * data->y_max;
	while (j < j_max)
	{
		if (i == 0)
			ft_color_palette1(data, j);
		else if (i == 1)
			ft_color_palette2(data, j);
		else
			ft_color_palette3(data, j);
		j++;
	}
}

static void	ft_color_palette1(t_data *data, int i)
{
	float	percent;

	percent = (data->map[i].z - data->z_min) / (data->z_max - data->z_min);
	if (percent <= 0.1f)
		data->map[i].color.code = 0xff0000;
	else if (percent <= 0.2f)
		data->map[i].color.code = 0xffa200;
	else if (percent <= 0.3f)
		data->map[i].color.code = 0xfff000;
	else if (percent <= 0.4f)
		data->map[i].color.code = 0x58ff00;
	else if (percent <= 0.5f)
		data->map[i].color.code = 0x00ff00;
	else if (percent <= 0.6f)
		data->map[i].color.code = 0x00ffea;
	else if (percent <= 0.7f)
		data->map[i].color.code = 0x00beff;
	else if (percent <= 0.8f)
		data->map[i].color.code = 0x0000ff;
	else if (percent <= 0.9f)
		data->map[i].color.code = 0x9500ff;
	else
		data->map[i].color.code = 0xff00f0;
}

static void	ft_color_palette2(t_data *data, int i)
{
	float	percent;

	percent = (data->map[i].z - data->z_min) / (data->z_max - data->z_min);
	if (percent <= 0.1f)
		data->map[i].color.code = 0xff00f0;
	else if (percent <= 0.2f)
		data->map[i].color.code = 0x9500ff;
	else if (percent <= 0.3f)
		data->map[i].color.code = 0x0000ff;
	else if (percent <= 0.4f)
		data->map[i].color.code = 0x00beff;
	else if (percent <= 0.5f)
		data->map[i].color.code = 0x00ffea;
	else if (percent <= 0.6f)
		data->map[i].color.code = 0x00ff00;
	else if (percent <= 0.7f)
		data->map[i].color.code = 0x58ff00;
	else if (percent <= 0.8f)
		data->map[i].color.code = 0xfff000;
	else if (percent <= 0.9f)
		data->map[i].color.code = 0xffa200;
	else
		data->map[i].color.code = 0xff0000;
}

static void	ft_color_palette3(t_data *data, int i)
{
	float	percent;

	percent = (data->map[i].z - data->z_min) / (data->z_max - data->z_min);
	if (percent <= 0.1f)
		data->map[i].color.code = 0xff0000;
	else if (percent <= 0.2f)
		data->map[i].color.code = 0xffa200;
	else if (percent <= 0.3f)
		data->map[i].color.code = 0xfff000;
	else if (percent <= 0.4f)
		data->map[i].color.code = 0x58ff00;
	else if (percent <= 0.5f)
		data->map[i].color.code = 0x00ff00;
	else if (percent <= 0.6f)
		data->map[i].color.code = 0x00ffea;
	else if (percent <= 0.7f)
		data->map[i].color.code = 0x00beff;
	else if (percent <= 0.8f)
		data->map[i].color.code = 0x0000ff;
	else if (percent <= 0.9f)
		data->map[i].color.code = 0x9500ff;
	else
		data->map[i].color.code = 0xff00f0;
}
