/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validfilecheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:25:45 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 15:36:30 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filecheck(char *arg, char *ext)
{
	int	fd;
	int	i;

	if (arg[0] == '.' && arg[1] != '/')
		printerror();
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '/')
		{
			if (arg[i + 1])
			{
				if (arg[i + 1] == '.')
					printerror();
			}
			else
				printerror();
		}
		i++;
	}
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		printerror();
	close(fd);
	extensioncheck(arg, ext);
}

int	maprowsize(char *filename)
{
	int		fd;
	int		rowsize;
	int		len;
	char	*line;

	len = 0;
	rowsize = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (len == 0)
			len = line_len(line);
		else if (line_len(line) != len)
		{
			free(line);
			printerror();
		}
		free(line);
		rowsize++;
	}
	return (rowsize);
}

void	getmap(char **map, char *file)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = line;
		i++;
	}
	if (map[i - 1][strlen_int(map[i - 1]) - 1] == '\n')
		printerror();
	map[i] = NULL;
	close(fd);
}
