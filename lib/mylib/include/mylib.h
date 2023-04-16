/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:54:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/16 12:57:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

////////// [ get ] //////////

char	*get_next_line(int fd);

////////// [ mem ] //////////

void	*ft_memset(void *b, int c, size_t len);

////////// [ other ] //////////

size_t	ft_atoi_base(const char *str, const char *set);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_free_split(char **tab);
char	**ft_split(char const *s, char c);
int		ft_tolower(int c);

////////// [ str ] //////////

size_t	ft_strlen(const char *s);

#endif
