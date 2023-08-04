/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:35:50 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/03 19:37:32 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_end_game(t_solong *g)
{
	mlx_delete_texture(g->t_player);
	mlx_delete_texture(g->t_wall);
	mlx_delete_texture(g->t_wall_ul);
	mlx_delete_texture(g->t_wall_up);
	mlx_delete_texture(g->t_wall_ur);
	mlx_delete_texture(g->t_wall_l);
	mlx_delete_texture(g->t_wall_r);
	mlx_delete_texture(g->t_wall_bl);
	mlx_delete_texture(g->t_wall_b);
	mlx_delete_texture(g->t_wall_br);
	mlx_delete_texture(g->t_floor);
	mlx_delete_texture(g->t_collect);
	mlx_delete_texture(g->t_exit);
}
