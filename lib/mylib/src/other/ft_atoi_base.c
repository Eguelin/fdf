/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:00 by eguelin           #+#    #+#             */
/*   Updated: 2023/03/03 18:01:39 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int		check_set(const char *set);
static size_t	set_chr(const char *set, const char c, size_t *n);

size_t	ft_atoi_base(const char *str, const char *set)
{
	size_t			i;
	size_t			n;
	size_t			len_set;
	unsigned int	somme;

	i = 0;
	len_set = ft_strlen(set);
	somme = 0;
	if (check_set(set))
		return (0);
	while (set_chr(set, str[i], &n))
	{
		somme = somme * len_set + n;
		i++;
	}
	return (somme);
}

static int	check_set(const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (set[i])
	{
		j = i + 1;
		while (set[j])
		{
			if (set[i] == set[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	set_chr(const char *set, const char c, size_t *n)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		*n = i;
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
