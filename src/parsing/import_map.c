/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/20 16:27:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_point(const char *path)
{
	char	buf[26];
	int		i;
	int		j;
	int		fd;

	fd = open(path, O_RDONLY);
	ft_bzero(buf, 26);
	j = 0;
	while (read(fd, buf, 25))
	{
		i = 0;
		while (buf[i])
		{
			if (buf[i] == ' ' || buf[i] == '\n')
				j++;
			buf[i] = 0;
			i++;
		}
	}
	close(fd);
	return (j);
}
