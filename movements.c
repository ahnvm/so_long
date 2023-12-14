/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:50:57 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 20:28:16 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveright(t_data *d)
{
	if (d->m->map[d->player_pos[0]][d->player_pos[1] + 1] != '1')
	{
		if (d->m->map[d->player_pos[0]][d->player_pos[1] + 1] == 'C')
			d->col_count--;
		if (d->player_pos[0] == d->exit_pos[0] && d->player_pos[1]
			+ 1 == d->exit_pos[1] && d->col_count == 0)
		{
			ft_putnbr_fd(d->movecount + 1, 1);
			write(1, "\n", 1);
			exit(0);
		}
		d->m->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->m->map[d->player_pos[0]][d->player_pos[1] + 1] = '0';
		put_map(d);
		d->m->map[d->player_pos[0]][d->player_pos[1] + 1] = 'P';
		d->player_pos[1] = d->player_pos[1] + 1;
		d->movecount++;
		ft_putnbr_fd(d->movecount, 1);
		write(1, "\n", 1);
	}
}

void	moveleft(t_data *d)
{
	if (d->m->map[d->player_pos[0]][d->player_pos[1] - 1] != '1')
	{
		if (d->m->map[d->player_pos[0]][d->player_pos[1] - 1] == 'C')
			d->col_count--;
		if (d->player_pos[0] == d->exit_pos[0] && d->player_pos[1]
			- 1 == d->exit_pos[1] && d->col_count == 0)
		{
			ft_putnbr_fd(d->movecount + 1, 1);
			write(1, "\n", 1);
			exit(0);
		}
		d->m->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->m->map[d->player_pos[0]][d->player_pos[1] - 1] = '0';
		put_map(d);
		d->m->map[d->player_pos[0]][d->player_pos[1] - 1] = 'P';
		d->player_pos[0] = d->player_pos[0];
		d->player_pos[1] = d->player_pos[1] - 1;
		d->movecount++;
		ft_putnbr_fd(d->movecount, 1);
		write(1, "\n", 1);
	}
}

void	moveup(t_data *d)
{
	if (d->m->map[d->player_pos[0] - 1][d->player_pos[1]] != '1')
	{
		if (d->m->map[d->player_pos[0] - 1][d->player_pos[1]] == 'C')
			d->col_count--;
		if (d->player_pos[0] - 1 == d->exit_pos[0]
			&& d->player_pos[1] == d->exit_pos[1] && d->col_count == 0)
		{
			ft_putnbr_fd(d->movecount + 1, 1);
			write(1, "\n", 1);
			exit(0);
		}
		d->m->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->m->map[d->player_pos[0] - 1][d->player_pos[1]] = '0';
		put_map(d);
		d->m->map[d->player_pos[0] - 1][d->player_pos[1]] = 'P';
		d->player_pos[0] = d->player_pos[0] - 1;
		d->player_pos[1] = d->player_pos[1];
		d->movecount++;
		ft_putnbr_fd(d->movecount, 1);
		write(1, "\n", 1);
	}
}

void	movedown(t_data *d)
{
	if (d->m->map[d->player_pos[0] + 1][d->player_pos[1]] != '1')
	{
		if (d->m->map[d->player_pos[0] + 1][d->player_pos[1]] == 'C')
			d->col_count--;
		if (d->player_pos[0] + 1 == d->exit_pos[0]
			&& d->player_pos[1] == d->exit_pos[1] && d->col_count == 0)
		{
			ft_putnbr_fd(d->movecount + 1, 1);
			write(1, "\n", 1);
			exit(0);
		}
		d->m->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->m->map[d->player_pos[0] + 1][d->player_pos[1]] = '0';
		put_map(d);
		d->m->map[d->player_pos[0] + 1][d->player_pos[1]] = 'P';
		d->player_pos[0] = d->player_pos[0] + 1;
		d->player_pos[1] = d->player_pos[1];
		d->movecount++;
		ft_putnbr_fd(d->movecount, 1);
		write(1, "\n", 1);
	}
}
