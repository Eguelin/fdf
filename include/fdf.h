/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/23 15:15:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/mylib/include/mylib.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

# ifndef AgA
#  define AgA (3.141593 / 180) * 80
# endif

# ifndef AgW
#  define AgW (3.141593 / 180) * 80
# endif

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coordinates {
	float	x;
	float	y;
	float	z;
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

int		ft_import_map(const char *path, t_data *data);

#endif
