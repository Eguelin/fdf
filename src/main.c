/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilienguelin <emilienguelin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/06 18:55:57 by emilienguel      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (argc != 2)
		return (0);
	ft_init_fdf(&data, argv[1]);
	ft_projection(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx_win, 4, 1L << 2, mouse_hook, &data);
	mlx_loop_hook(data.mlx, ft_image, &data);
	mlx_loop(data.mlx);
	return (0);
}
