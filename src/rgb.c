/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilienguelin <emilienguelin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:59:50 by emilienguel       #+#    #+#             */
/*   Updated: 2023/03/06 19:10:02 by emilienguel      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rgb2(t_trgb *trgb);

void	ft_rgb(t_data *data)
{
	int	i;
	int	i_max;

	i = 0;
	i_max = data->x_max * data->y_max;
	while (i < i_max && data->rgb_on_off)
	{
		ft_rgb2(&data->map[i].color.trgb);
		i++;
	}
}

static void	ft_rgb2(t_trgb *trgb)
{
	if (trgb->r == 0xff && trgb->g < 0xff && trgb->b == 0)
		trgb->g++;
	else if (trgb->r > 0 && trgb->g == 0xff && trgb->b == 0)
		trgb->r--;
	else if (trgb->r == 0 && trgb->g == 0xff && trgb->b < 0xff)
		trgb->b++;
	else if (trgb->r == 0 && trgb->g > 0 && trgb->b == 0xff)
		trgb->g--;
	else if (trgb->r < 0xff && trgb->g == 0 && trgb->b == 0xff)
		trgb->r++;
	else
		trgb->b--;
}
