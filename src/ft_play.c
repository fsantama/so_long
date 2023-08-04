/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:34 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/04 18:53:54 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_end_game(t_solong *g)
{
	if (g->n_collect > 0)
		ft_putstr_fd("There are still collectibles to collect\n", 1);
	else
	{
		ft_putstr_fd("YOU WIN. CONGRATULATIONS\n", 1);
		exit (EXIT_SUCCESS);
	}
}

void	check_move(t_solong *g)
{
	if (g->read_map[g->y_mov][g->x_mov] == 'C')
		g->n_collect--;
	if (g->read_map[g->y_mov][g->x_mov] == 'C' ||
			g->read_map[g->y_mov][g->x_mov] == '0')
	{
		g->read_map[g->y_pos][g->x_pos] = '0';
		g->read_map[g->y_mov][g->x_mov] = 'P';
		g->x_pos = g->x_mov;
		g->y_pos = g->y_mov;
		g->moves++;
		ft_printf("Total moves = %d\n", g->moves);
	}
	if (g->read_map[g->y_mov][g->x_mov] == 'E')
		check_end_game(g);
	draw_map(g);
}

void	ft_play(mlx_key_data_t keydata, void *param)
{
	t_solong	*g;

	g = param;
	g->x_mov = g->x_pos;
	g->y_mov = g->y_pos;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		g->y_mov--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		g->x_mov--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		g->y_mov++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		g->x_mov++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	check_move(g);
	return ;
}
