/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 16:13:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../lib/mylib/include/mylib.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

# define PI 3.141592653589793
# define HEIGHT 2058
# define LENGTH 3840
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define KEY_ESC 65307
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KEY_7 55
# define KEY_9 57
# define KEY_0 48
# define KEY_DASH_UNDERSCORE 45
# define KEY_EQUALS_PLUS 61
# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_OPEN_BRACKET 91
# define KEY_CLOSE_BRACKET 93
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP_ARROW 65362
# define KEY_LEFT_ARROW 65361
# define KEY_DOWN_ARROW 65364
# define KEY_RIGHT_ARROW 65363

typedef struct s_trgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}				t_trgb;

typedef union u_color
{
	t_trgb	trgb;
	int		code;
}			t_color;

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
	t_color	color;
}				t_coord;

typedef struct s_header
{
	void	*mlx;
	void	*mlx_win;
	void	*ptr;
}				t_header;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_coord		*map;
	t_header	header;
	const char	*path;
	int			x_max;
	int			y_max;
	int			z_min;
	int			z_max;
	int			rgb_on_off;
	double		intensity;
	double		mid_height;
	double		mid_length;
	double		a;
	double		b;
	double		c;
	double		zoom;
}				t_data;

////////// [ camera_bonus.c ] //////////
void	ft_isometric(t_data *data);
void	ft_parallel(t_data *data);
void	ft_front(t_data *data);
void	ft_above(t_data *data);

////////// [ color_bonus.c ] //////////
int		ft_gradient_color(t_color *clr1, t_color *clr2, double line, int i);
void	ft_change_color(t_data *data, int i);

////////// [ hook_bonus.c ] //////////
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);

////////// [ image_bonus.c ] //////////
int		ft_image(t_data *data);

////////// [ parsing_bonus.c ] //////////
void	ft_import_map(const char *path, t_data *data);

////////// [ projection_bonus.c ] //////////
void	ft_projection(t_data *data);

////////// [ rgb_bonus.c ] //////////
void	ft_rgb(t_data *data);

////////// [ tool_bonus.c ] //////////
void	ft_init_fdf(t_data *data, const char *arg);
int		ft_close(t_data *data);
int		ft_exit(t_data *data);

#endif
