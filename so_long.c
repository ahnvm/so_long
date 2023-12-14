/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:25:34 by acan              #+#    #+#             */
/*   Updated: 2023/10/15 20:40:57 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*alldata;

	if (ac == 2)
	{
		filecheck(av[1], ".ber");
		alldata = malloc(sizeof(t_data));
		alldata->m = malloc(sizeof(t_map));
		alldata->m->y = maprowsize(av[1]);
		alldata->m->map = malloc(sizeof(char *) * (alldata->m->y + 1));
		alldata->movecount = 0;
		alldata->exit_pos[0] = -1;
		alldata->exit_pos[1] = -1;
		getmap(alldata->m->map, av[1]);
		alldata->m->x = strlen_int(alldata->m->map[0]) - 1;
		finalmapcheck(alldata->m->map, alldata);
		if (alldata->m->x >= 128 || alldata->m->y >= 128)
			printerror();
		game_init(alldata);
	}
	else
		printerror();
}
