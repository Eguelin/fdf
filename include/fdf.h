/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/21 10:33:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/mylib/include/mylib.h"
# include <fcntl.h>

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coordinates {
	int		x;
	int		y;
	int		z;
}				t_coord;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_coord	*map;
	int		x;
	int		y;
}				t_data;

void	ft_size_file(const char *path, t_data *data);
int		ft_import_map(const char *path, t_data *data);

#endif
