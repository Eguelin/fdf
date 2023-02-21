/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/21 17:05:02 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_import_coord(int fd, int y, t_data *data);

int	ft_import_map(const char *path, t_data *data)
{
	int	fd;
	int	y;

	fd = 0;
	y = 1;
	ft_size_file(path, data);
	data->map = malloc(sizeof(t_coord) * data->x * data->y);
	if (!(data->map))
		return (-1);
	while (y <= data->y)
	{
		ft_import_coord(fd, y, data);
		y++;
	}
	return (0);
}

void	ft_size_file(const char *path, t_data *data)
{
	char	buf[26];
	char	c;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	ft_bzero(buf, 26);
	c = ' ';
	while (read(fd, buf, 25))
	{
		i = 0;
		while (buf[i])
		{
			if (c != ' ' && (buf[i] == ' ' || buf[i] == '\n') && data->y == 0)
				data->x++;
			if (buf[i] == '\n')
				data->y++;
			c = buf[i];
			buf[i] = 0;
			i++;
		}
	}
	close(fd);
}

int	ft_import_coord(int fd, int y, t_data *data)
{
	int	i;
	int	x;
	//char	**line;

	x = 1;
	i = fd;
	i = (y - 1) * data->x;
	while (x <= data->x)
	{
		data->map[i].x = x++;
		data->map[i].y = y;
		data->map[i].z = 0;
		i++;
	}
	return (0);
}
