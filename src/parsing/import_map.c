/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:17 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/16 16:27:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_line(int fd)
{
	char	*buf;
	int		i;
	int		j;

	buf = malloc(sizeof(char) * 26);
	if (!buf)
		return (-1);
	ft_bzero(buf, 26);
	j = 0;
	while (read(fd, buf, 25))
	{
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				j++;
			buf[i] = 0;
			i++;
		}
	}
	free(buf);
	return (j);
}
