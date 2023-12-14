/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:24:30 by acan              #+#    #+#             */
/*   Updated: 2023/10/22 14:18:00 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
	void	*exit;
	void	*pl;
	void	*col;
	void	*wall;
	void	*way;
}			t_map;

typedef struct s_data
{
	int		player_pos[2];
	int		exit_pos[2];
	int		col_count;
	int		movecount;
	void	*ptr;
	void	*win;
	t_map	*m;
}			t_data;

void		filecheck(char *arg, char *ext);
void		printerror(void);
void		extensioncheck(char *filename, char *ext);
int			maprowsize(char *filename);
int			line_len(char *line);
void		getmap(char **map, char *file);
void		checkmapchars(char **str);
void		isclosedmap(char **map);
void		exitcheck(char **map, t_data *data);
void		playercheck(char **map, t_data *data);
void		collectiblecheck(char **map, t_data *data);
void		finalmapcheck(char **map, t_data *data);
char		*my_strdup(char *s1);
int			arglen(char **arg);
void		freemap(char **map);
void		game_init(t_data *data);
int			exitgame(int key, t_data *data);
void		moveleft(t_data *d);
void		moveright(t_data *d);
void		moveup(t_data *d);
void		movedown(t_data *d);
void		put_map(t_data *data);
void		ft_putnbr_fd(int n, int fd);

#endif