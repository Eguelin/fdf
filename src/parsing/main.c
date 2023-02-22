/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/22 13:30:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.x = 0;
	data.y = 0;
	(void)argc;
	ft_import_map(argv[1], &data);
	ft_printf("x = %d y = %d \n", data.x, data.y);
	while (i < data.x * data.y)
	{
		ft_printf("%d. x = %d y = %d z = %d\n", i, data.map[i].x, \
		data.map[i].y, data.map[i].z);
		i++;
	}
	free(data.map);
	return (0);
}
