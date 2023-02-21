/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/21 11:54:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_data	data;

	data.x = 0;
	data.y = 0;
	(void)argc;
	ft_import_map(argv[1], &data);
	ft_printf("x = %d y = %d | x = %d y = %d z = %d x2 = %d", data.x, data.y, data.map->x, data.map->y, data.map->z, data.map[1].x);
	free(data.map);
	return (0);
}
