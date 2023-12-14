/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:06:37 by acan              #+#    #+#             */
/*   Updated: 2023/08/12 18:31:39 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
#endif