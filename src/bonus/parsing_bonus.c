/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/17 14:50:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void			ft_size_file(const char *path, t_data *data);
static int			ft_import_line(int fd, int y, t_data *data);
static int			ft_import_coord(int y, char **word, t_data *data);
static unsigned	int	ft_import_color(char *word);

void	ft_import_map(const char *path, t_data *data)
{
	int		fd;
	int		y;

	y = 1;
	ft_size_file(path, data);
	data->map = malloc(sizeof(t_coord) * data->x_max * data->y_max);
	if (!(data->map))
		exit(1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(data->map);
		exit(1);
	}
	while (y <= data->y_max)
	{
		if (ft_import_line(fd, y, data))
		{
			close(fd);
			free(data->map);
			exit(1);
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
		exit(1);
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

static int	ft_import_line(int fd, int y, t_data *data)
{
	char	*line;
	char	**word;

	line = get_next_line(fd);
	if (!line)
		return (1);
	word = ft_split(line, ' ');
	if (!word)
		return (free(line), 1);
	if (ft_import_coord(y, word, data))
		return (free(line), ft_free_split(word), 1);
	return (free(line), ft_free_split(word), 0);
}

static int	ft_import_coord(int y, char **word, t_data *data)
{
	int		i;
	int		x;

	x = 1;
	i = (y - 1) * data->x_max;
	while (x <= data->x_max)
	{
		if (!word[x - 1])
			return (1);
		data->map[i].x = (x - (((double)data->x_max +1) * 0.5));
		data->map[i].y = (y - (((double)data->y_max +1) * 0.5));
		data->map[i].z = ft_atoi(word[x - 1]);
		if (data->z_min > data->map[i].z)
			data->z_min = data->map[i].z;
		if (data->z_max < data->map[i].z)
			data->z_max = data->map[i].z;
		data->map[i].color.code = ft_import_color(word[x - 1]);
		i++;
		x++;
	}
	return (0);
}

static unsigned	int	ft_import_color(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		word[i] = ft_tolower(word[i]);
		i++;
	}
	i = 0;
	while (word[i])
	{
		if (word[i] == 'x')
			return (ft_atoi_base(word + i + 1, "0123456789abcdef"));
		i++;
	}
	return (0xFFFFFFFF);
}
