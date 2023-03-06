/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilien <emilien@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:49 by emilien           #+#    #+#             */
/*   Updated: 2023/03/06 20:17:11 by emilien          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_color_palette1(t_data *data, int i);
static void	ft_color_palette2(t_data *data, int i);

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
		if (i == 1)
			ft_color_palette1(data, j);
		else
			ft_color_palette2(data, j);
		j++;
	}
}

static void	ft_color_palette1(t_data *data, int i)
{
	float	percent;

	percent = (data->map[i].z - data->z_min) / (data->z_max - data->z_min);
	if (percent <= 0.09f)
		data->map[i].color.code = 0xff0000;
	else if (percent <= 0.18f)
		data->map[i].color.code = 0xff8800;
	else if (percent <= 0.27f)
		data->map[i].color.code = 0xffff00;
	else if (percent <= 0.36f)
		data->map[i].color.code = 0x88ff00;
	else if (percent <= 0.45f)
		data->map[i].color.code = 0x00ff00;
	else if (percent <= 0.54f)
		data->map[i].color.code = 0x00ff88;
	else if (percent <= 0.63f)
		data->map[i].color.code = 0x00ffff;
	else if (percent <= 0.72f)
		data->map[i].color.code = 0x0088ff;
	else if (percent <= 0.81f)
		data->map[i].color.code = 0x0000ff;
	else if (percent <= 0.90f)
		data->map[i].color.code = 0x8800ff;
	else
		data->map[i].color.code = 0xff00ff;
}

static void	ft_color_palette2(t_data *data, int i)
{
	float	percent;

	percent = (data->map[i].z - data->z_min) / (data->z_max - data->z_min);
	if (percent <= 0.09f)
		data->map[i].color.code = 0xff00ff;
	else if (percent <= 0.18f)
		data->map[i].color.code = 0x8800ff;
	else if (percent <= 0.27f)
		data->map[i].color.code = 0x0000ff;
	else if (percent <= 0.36f)
		data->map[i].color.code = 0x0088ff;
	else if (percent <= 0.45f)
		data->map[i].color.code = 0x00ffff;
	else if (percent <= 0.54f)
		data->map[i].color.code = 0x00ff88;
	else if (percent <= 0.63f)
		data->map[i].color.code = 0x00ff00;
	else if (percent <= 0.72f)
		data->map[i].color.code = 0x88ff00;
	else if (percent <= 0.81f)
		data->map[i].color.code = 0xffff00;
	else if (percent <= 0.90f)
		data->map[i].color.code = 0xff8800;
	else
		data->map[i].color.code = 0xff0000;
}
