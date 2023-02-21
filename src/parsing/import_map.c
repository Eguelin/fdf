/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/21 10:34:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_import_map(const char *path, t_data *data)
{
	//int	i;
	int	size;

	//i = 0;
	ft_size_file(path, data);
	size = (data->x * data->y) + 1;
	data->map = malloc(sizeof(t_coord) * size);
	if (!(data->map))
		return (-1);
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
