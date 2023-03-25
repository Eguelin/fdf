/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/22 14:46:20 by eguelin          ###   ########lyon.fr   */
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
# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472
# define KEY_F4 65473
# define KEY_F5 65474
# define KEY_F6 65475
# define KEY_F7 65476
# define KEY_F8 65477
# define KEY_F9 65478
# define KEY_F10 65479
# define KEY_F11 65480
# define KEY_F12 65481
# define KEY_GRAVE_ACCENT 96
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KEY_7 55
# define KEY_8 56
# define KEY_9 57
# define KEY_0 48
# define KEY_DASH_UNDERSCORE 45
# define KEY_EQUALS_PLUS 61
# define KEY_BACKSPACE 65288
# define KEY_TAB 65289
# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_R 114
# define KEY_T 116
# define KEY_Y 121
# define KEY_U 117
# define KEY_I 105
# define KEY_O 111
# define KEY_P 112
# define KEY_OPEN_BRACKET 91
# define KEY_CLOSE_BRACKET 93
# define KEY_BACKSLASH 92
# define KEY_CAPS_LOCK 65509
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define KEY_J 106
# define KEY_K 107
# define KEY_L 108
# define KEY_SEMICOLON 59
# define KEY_SINGLE_QUOTE 39
# define KEY_ENTER 65293
# define KEY_LEFT_SHIFT 65505
# define KEY_Z 122
# define KEY_X 120
# define KEY_C 99
# define KEY_V 118
# define KEY_B 98
# define KEY_N 110
# define KEY_M 109
# define KEY_COMMA 44
# define KEY_PERIOD 46
# define KEY_SLASH 47
# define KEY_RIGHT_SHIFT 65506
# define KEY_LEFT_COMMAND 65507
# define KEY_LEFT_ALT 65513
# define KEY_SPACE 32
# define KEY_RIGHT_ALT 65514
# define KEY_MENU 65383
# define KEY_RIGHT_COMMAND 65508
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
	float	x;
	float	y;
	float	z;
	float	x_bis;
	float	y_bis;
	float	z_bis;
	t_color	color;
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
	int			z_min;
	int			z_max;
	int			rgb_on_off;
	float		intensity;
	float		mid_height;
	float		mid_length;
	float		a;
	float		b;
	float		c;
	float		zoom;
}				t_data;

void	ft_init_fdf(t_data *data, const char *arg);
void	ft_import_map(const char *path, t_data *data);
void	ft_projection(t_data *data);
void	ft_isometric(t_data *data);
void	ft_parallel(t_data *data);
void	ft_front(t_data *data);
void	ft_above(t_data *data);
void	ft_change_color(t_data *data, int i);
void	ft_rgb(t_data *data);

int		ft_image(t_data *data);
int		ft_close(t_data *data);
int		ft_exit(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		ft_gradient_color(t_color *clr1, t_color *clr2, float line, int i);

#endif
