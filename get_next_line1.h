/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:37:17 by rturnip           #+#    #+#             */
/*   Updated: 2021/01/27 14:23:21 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE1_H
# define GET_NEXT_LINE1_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

int			get_next_line(int fd, char **line);
size_t		ft_strlen1(const char *str);
char		*ft_strdup1(char *s1);
char		*ft_strjoin1(char *s1, char *s2);
int			ft_str_n(char *s, char *buf);
char		*ft_reborn_line(char *backup);
char		*ft_return_line(char *backup);
int			ft_strchr1(const char *s, int c);
#endif
