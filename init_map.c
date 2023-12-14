/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:04:45 by acan              #+#    #+#             */
/*   Updated: 2023/10/22 14:19:53 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *d, char **map, int i, int j)
{
	if (map[i][j] == '0')
		mlx_put_image_to_window(d->ptr, d->win, d->m->way, j * 64, i * 64);
	if (map[i][j] == '1')
		mlx_put_image_to_window(d->ptr, d->win, d->m->wall, j * 64, i * 64);
	if (map[i][j] == 'P')
		mlx_put_image_to_window(d->ptr, d->win, d->m->pl, j * 64, i * 64);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(d->ptr, d->win, d->m->exit, j * 64, i * 64);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(d->ptr, d->win, d->m->col, j * 64, i * 64);
}

void	put_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->m->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			put_image(data, map, i, j);
		}
	}
}

int	movement(int key, t_data *d)
{
	if (key == 53)
		exit(0);
	else if (key == 2)
		moveright(d);
	else if (key == 0)
		moveleft(d);
	else if (key == 13)
		moveup(d);
	else if (key == 1)
		movedown(d);
	if (d->player_pos[0] == d->exit_pos[0]
		&& d->player_pos[1] == d->exit_pos[1])
	{
		mlx_clear_window(d->ptr, d->win);
		d->m->map[d->exit_pos[0]][d->exit_pos[1]] = 'E';
		put_map(d);
		d->m->map[d->exit_pos[0]][d->exit_pos[1]] = 'P';
	}
	else
		d->m->map[d->exit_pos[0]][d->exit_pos[1]] = 'E';
	put_map(d);
	return (0);
}

static void	set_images(t_data *data)
{
	int		x;
	int		y;
	t_map	*m;

	m = data->m;
	m->pl = mlx_xpm_file_to_image(data->ptr, "textures/player.xpm", &x, &y);
	m->wall = mlx_xpm_file_to_image(data->ptr, "textures/wall.xpm", &x, &y);
	m->way = mlx_xpm_file_to_image(data->ptr, "textures/way.xpm", &x, &y);
	m->exit = mlx_xpm_file_to_image(data->ptr, "textures/exit.xpm", &x, &y);
	m->col = mlx_xpm_file_to_image(data->ptr, "textures/collect.xpm", &x, &y);
	if (!m->pl || !m->wall || !m->way || !m->exit || !m->col)
		printerror();
}

void	game_init(t_data *data)
{
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, data->m->x * 64, data->m->y * 64,
			"so_long");
	set_images(data);
	put_map(data);
	mlx_hook(data->win, 2, 1L << 0, &movement, data);
	mlx_hook(data->win, 17, 1L << 0, &exitgame, data);
	mlx_loop(data->ptr);
}
