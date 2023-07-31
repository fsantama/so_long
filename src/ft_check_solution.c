/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:29:20 by fsantama          #+#    #+#             */
/*   Updated: 2023/07/31 18:49:44 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_path(t_solong *g, int x, int y)
{
	if (g->copy_map[y][x] == 'E')
	{
		g->copy_map[y][x] = '1';
		return;
	}
	g->copy_map[y][x] = '1';
	if (g->copy_map[y + 1][x] != '1')
		check_path(g, x, y + 1);
	if (g->copy_map[y - 1][x] != '1')
		check_path(g, x, y - 1);
	if (g->copy_map[y][x + 1] != '1')
		check_path(g, x + 1, y);
	if (g->copy_map[y][x - 1] != '1')
		check_path(g, x - 1, y);
}

void	ft_check_solution(t_solong *g)
{
	int	i;

	i = 0;
	check_path(g, g->x_pos, g->y_pos);
	while (g->copy_map[i++])
	{
		if (ft_strchr(g->copy_map[i], 'E') || ft_strchr(g->copy_map[i], 'C'))
			ft_error(g, INVALID_SOLUTION);
	}
}
