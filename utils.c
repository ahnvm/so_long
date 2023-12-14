/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:26:47 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 19:09:16 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	extensioncheck(char *filename, char *ext)
{
	int	i;
	int	j;

	i = strlen_int(filename) - 4;
	j = 0;
	while (filename[i] && ext[j])
	{
		if (filename[i] != ext[j])
			printerror();
		i++;
		j++;
	}
}

char	*my_strdup(char *s1)
{
	char	*dst;
	int		count;
	int		size;

	count = 0;
	size = strlen_int(s1);
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (count < size)
	{
		dst[count] = s1[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

int	arglen(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}
