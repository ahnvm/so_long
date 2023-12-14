/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:52 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 15:30:12 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		strlen_int(char *s);
char	*buf_to_text(char *text, char *buf);
int		hasnlornull(char *s);
char	*find_line(int fd, char *text);
char	*seperate_line(char	*text);
char	*cut_line(char *text);
char	*ft_calloc(int count);
char	*get_next_line(int fd);
void	freemap(char **map);
#endif