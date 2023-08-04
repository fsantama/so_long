/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:36:23 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/03 19:37:57 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_draw_walls(t_solong *g, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_draw_texture(g->img, g->t_wall_ul, (x * SPR), (y * SPR));
	else if (x < g->col - 1 && y == 0)
		mlx_draw_texture(g->img, g->t_wall_up, (x * SPR), (y * SPR));
	else if (y == 0 && x == g->col - 1)
		mlx_draw_texture(g->img, g->t_wall_ur, (x * SPR), (y * SPR));
	else if (y < g->row - 1 && x == 0)
		mlx_draw_texture(g->img, g->t_wall_l, (x * SPR), (y * SPR));
	else if (y < g->row - 1 && x == g->col - 1)
		mlx_draw_texture(g->img, g->t_wall_r, (x * SPR), (y * SPR));
	else if (y == g->row - 1 && x == 0)
		mlx_draw_texture(g->img, g->t_wall_bl, (x * SPR), (y * SPR));
	else if (y == g->row -1 && x == g->col - 1)
		mlx_draw_texture(g->img, g->t_wall_br, (x * SPR), (y * SPR));
	else if (y == g->row -1 && x < g->col - 1)
		mlx_draw_texture(g->img, g->t_wall_b, (x * SPR), (y * SPR));
	else
		mlx_draw_texture(g->img, g->t_wall, (x * SPR), (y * SPR));
}
