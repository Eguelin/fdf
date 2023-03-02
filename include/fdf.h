/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilien <emilien@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/02 23:58:18 by emilien          ###   ########lyon.fr   */
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

# define ESC 65307
# define F1 65470
# define F2 65471
# define F3 65472
# define F4 65473
# define F5 65474
# define F6 65475
# define F7 65476
# define F8 65477
# define F9 65478
# define F10 65479
# define F11 65480
# define F12 65481
# define GRAVE_ACCENT 96
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 53
# define SIX 54
# define SEVEN 55
# define EIGHT 56
# define NINE 57
# define ZERO 48
# define DASH_UNDERSCORE 45
# define EQUALS_PLUS 61
# define BACKSPACE 65288
# define TAB 65289
# define Q 113
# define W 119
# define E 101
# define R 114
# define T 116
# define Y 121
# define U 117
# define I 105
# define O 111
# define P 112
# define OPEN_BRACKET 91
# define CLOSE_BRACKET 93
# define BACKSLASH 92
# define CAPS_LOCK 65509
# define A 97
# define S 115
# define D 100
# define F 102
# define G 103
# define H 104
# define J 106
# define K 107
# define L 108
# define SEMICOLON 59
# define SINGLE_QUOTE 39
# define ENTER 65293
# define LEFT_SHIFT 65505
# define Z 122
# define X 120
# define C 99
# define V 118
# define B 98
# define N 110
# define M 109
# define COMMA 44
# define PERIOD 46
# define SLASH 47
# define RIGHT_SHIFT 65506
# define LEFT_COMMAND 65507
# define LEFT_ALT 65513
# define SPACE 32
# define RIGHT_ALT 65514
# define MENU 65383
# define RIGHT_COMMAND 65508
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

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
	float	x_bis;
	float	y_bis;
	float	z_bis;
}				t_coord;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_coord	*map;
	int		x_max;
	int		y_max;
	float	intensity;
	float	mid_height;
	float	mid_length;
	float	a;
	float	b;
	float	c;
	float	zoom;

}				t_data;

void	ft_init_fdf(t_data *data, const char *arg);
void	ft_import_map(const char *path, t_data *data);
void	ft_projection(t_data *data);

int		ft_image(t_data *data);
int		ft_close(t_data *data);
int		ft_exit(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);

#endif
