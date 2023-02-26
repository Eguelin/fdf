/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/26 14:21:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_size_file(const char *path, t_data *data);
static int	ft_import_coord(int fd, int y, t_data *data);

void	ft_import_map(const char *path, t_data *data)
{
	int		fd;
	int		y;

	y = 1;
	ft_size_file(path, data);
	data->map = malloc(sizeof(t_coord) * data->x_max * data->y_max);
	if (!(data->map))
		exit (1);
	fd = open(path, O_RDONLY);
	while (y <= data->y_max)
	{
		if (ft_import_coord(fd, y, data))
		{
			close(fd);
			exit (1);
		}
		y++;
	}
	close(fd);
}

static void	ft_size_file(const char *path, t_data *data)
{
	char	buf[BUFFER_SIZE + 1];
	char	c;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit (1);
	ft_bzero(buf, BUFFER_SIZE + 1);
	c = ' ';
	while (read(fd, buf, BUFFER_SIZE))
	{
		i = 0;
		while (buf[i])
		{
			if (c != ' ' && (buf[i] == ' ' || buf[i] == '\n') && \
			data->y_max == 0)
				data->x_max++;
			if (buf[i] == '\n')
				data->y_max++;
			c = buf[i];
			buf[i++] = 0;
		}
	}
	close(fd);
}

static int	ft_import_coord(int fd, int y, t_data *data)
{
	int		i;
	int		x;
	char	*line;
	char	**word;

	line = get_next_line(fd);
	if (!line)
		return (1);
	word = ft_split(line, ' ');
	if (!word)
		return (free(line), 1);
	x = 1;
	i = (y - 1) * data->x_max;
	while (x <= data->x_max)
	{
		data->map[i].x = (x - (((float)data->x_max +1) / 2));
		data->map[i].y = (y - (((float)data->y_max +1) / 2));
		data->map[i].z = ft_atoi(word[x - 1]);
		data->map[i].x_bis = data->map[i].x * data->zoom;
		data->map[i].y_bis = data->map[i].y * data->zoom;
		data->map[i].z_bis = data->map[i].z * data->zoom;
		x++;
		i++;
	}
	return (free(line), ft_free_split(word), 0);
}
