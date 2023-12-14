/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrols2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:51 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 19:45:43 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	accesscheck(char **map, int x, int y)
{
	if (y < 1 || x >= (arglen(map) - 1) || x < 1 || y >= strlen_int(map[0])
		|| map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	accesscheck(map, x - 1, y);
	accesscheck(map, x + 1, y);
	accesscheck(map, x, y - 1);
	accesscheck(map, x, y + 1);
}

static void	reachcheck(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				freemap(map);
			j++;
		}
		j = 0;
		i++;
	}
}

void	finalmapcheck(char **map, t_data *data)
{
	char	**map2;
	int		i;

	map2 = malloc(sizeof(char *) * arglen(map) + 1);
	i = 0;
	while (map[i])
	{
		map2[i] = my_strdup(map[i]);
		i++;
	}
	map2[i] = 0;
	checkmapchars(map2);
	playercheck(map2, data);
	isclosedmap(map2);
	exitcheck(map2, data);
	if (data->exit_pos[0] == -1 && data->exit_pos[1] == -1)
		freemap(map);
	collectiblecheck(map2, data);
	accesscheck(map2, data->player_pos[0], data->player_pos[1]);
	i = 0;
	reachcheck(map2);
	i = 0;
	while (map2[i])
		free(map2[i++]);
	free(map2);
}
