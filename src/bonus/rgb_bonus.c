/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:59:50 by emilienguel       #+#    #+#             */
/*   Updated: 2023/04/17 12:59:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_rgb_2(t_trgb *trgb);

void	ft_rgb(t_data *data)
{
	int	i;
	int	j;
	int	i_max;

	i = 0;
	i_max = data->x_max * data->y_max;
	while (i < i_max && data->rgb_on_off)
	{
		j = 10;
		while (j)
		{
			ft_rgb_2(&data->map[i].color.trgb);
			j--;
		}
		i++;
	}
}

static void	ft_rgb_2(t_trgb *trgb)
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
