/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrols1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:18:41 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 18:02:02 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmapchars(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == 'P'
				|| str[i][j] == 'E' || str[i][j] == 'C' || str[i][j] == '\n')
				j++;
			else
				freemap(str);
		}
		j = 0;
		i++;
	}
}

void	isclosedmap(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n')
		if (map[0][i++] != '1')
			freemap(map);
	i = 0;
	while (map[arglen(map) - 1][i])
		if (map[arglen(map) - 1][i++] != '1')
			freemap(map);
	i = 0;
	while (map[i])
		if (map[i++][0] != '1')
			freemap(map);
	i = 0;
	while (map[i])
		if (map[i++][strlen_int(map[0]) - 2] != '1')
			freemap(map);
}

void	exitcheck(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E' && flag == 0)
			{
				data->exit_pos[0] = i;
				data->exit_pos[1] = j;
				flag = 1;
			}
			else if (map[i][j] == 'E' && flag != 0)
				freemap(map);
			j++;
		}
		j = 0;
		i++;
	}
}

void	playercheck(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' && flag == 0)
			{
				data->player_pos[0] = i;
				data->player_pos[1] = j;
				flag = 1;
			}
			else if (map[i][j] == 'P' && flag != 0)
				freemap(map);
			j++;
		}
		j = 0;
		i++;
	}
}

void	collectiblecheck(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->col_count = 0;
	while (map[i])
	{
		while (map[i][j])
			if (map[i][j++] == 'C')
				data->col_count++;
		j = 0;
		i++;
	}
	if (data->col_count == 0)
	{
		freemap(map);
	}
}
