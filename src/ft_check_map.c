/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:55:21 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/01 20:27:42 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_objects(t_solong *g)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < g->row - 1)
	{
		x = 0;
		while (x++ < g->col - 1)
		{
			if (g->read_map[y][x] == 'P')
			{
				g->n_player++;
				g->x_pos = x;
				g->y_pos = y;
			}
			else if (g->read_map[y][x] == 'C')
				g->n_collect++;
			else if (g->read_map[y][x] == 'E')
				g->n_exit++;
			else if (g->read_map[y][x] != '0' && g->read_map[y][x] != '1')
				ft_error(g, INVALID_CHAR);
		}
	}
	if (g->n_player != 1 || g->n_collect < 1 || g->n_exit != 1)
		ft_error(g, INVALID_OBJECTS);
}

void	check_limits_map(t_solong *g)
{
	int	i;

	i = 0;
	while (g->read_map[0][i])
	{
		if ((g->read_map[0][i] != '1') || (g->read_map[g->row - 1][i] != '1'))
			ft_error(g, LIMIT_MAP);
		i++;
	}
	i = 0;
	while (i < g->row)
	{
		if ((g->read_map[i][0] != '1') || (g->read_map[i][g->col - 1] != '1'))
			ft_error(g, LIMIT_MAP);
		i++;
	}
}

void	valid_map(t_solong *g)
{
	int	i;

	i = 1;
	g->col = ft_strlennew(g->read_map[0]);
	while (g->read_map[i])
	{
		if (g->col != ft_strlennew(g->read_map[i]))
			ft_error(g, NO_QUADRILATERAL_MAP);
		i++;
	}
	g->row = i;
}

char	*check_map_name(t_solong *g, char *map)
{
	char	*extension;
	int		i_ex;
	int		i;

	extension = ".ber";
	i_ex = 3;
	i = ft_strlen(map);
	while (i_ex >= 0)
	{
		if (map[--i] != extension[i_ex--])
			ft_error(g, INVALID_NAME_MAP);
	}
	return (map);
}

void	ft_check_map(char *map, t_solong *g)
{
	g->n_player = 0;
	g->n_collect = 0;
	g->n_exit = 0;
	g->read_map = 0;
	g->map = check_map_name(g, map);
	g->fd_map = open(map, O_RDONLY);
	if (g->fd_map < 0)
		ft_error(g, INVALID_FD);
	ft_read_map(g);
	valid_map(g);
	check_limits_map(g);
	check_objects(g);
	ft_check_solution(g);
}
