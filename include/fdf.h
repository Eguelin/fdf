/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 15:57:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/mylib/include/mylib.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

# define PI 3.141592653589793
# define HEIGHT 2058
# define LENGTH 3840

# define KEY_ESC 65307

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
	double	x_bis;
	double	y_bis;
	double	z_bis;
}				t_coord;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_coord		*map;
	const char	*path;
	int			x_max;
	int			y_max;
	double		mid_height;
	double		mid_length;
	double		zoom;
}				t_data;

////////// [ image.c ] //////////
int		ft_image(t_data *data);

////////// [ parsing.c ] //////////
void	ft_import_map(const char *path, t_data *data);

////////// [ projection.c ] //////////
void	ft_projection(t_data *data);

////////// [ tool.c ] //////////
void	ft_init_fdf(t_data *data, const char *arg);
int		key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);
int		ft_exit(t_data *data);

#endif
