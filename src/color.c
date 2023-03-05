/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilien <emilien@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:49 by emilien           #+#    #+#             */
/*   Updated: 2023/03/04 21:36:45 by emilien          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_gradient_color(t_color *clr1, t_color *clr2, float line, int i)
{
	t_color	clr3;

	if (clr1->code == clr2->code)
		return (clr1->code);
	clr3.argb.r = clr1->argb.r + i * (clr2->argb.r - clr1->argb.r) / line;
	clr3.argb.g = clr1->argb.g + i * (clr2->argb.g - clr1->argb.g) / line;
	clr3.argb.b = clr1->argb.b + i * (clr2->argb.b - clr1->argb.b) / line;
	return (clr3.code);
}

/*void	ft_change_color(t_data *data)
{
	int	i;
	int	i_max;

	i = 0;
	i_max  = data->x_max * data->y_max;
	while (i < i_max)
	{
		data->map[i].color.code =	0;
		i++;
	}
}*/
