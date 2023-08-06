/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maharta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:52:05 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/06 18:13:33 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_maharta_2(t_solong *g)
{
	if (g->t_floor)
		mlx_delete_texture(g->t_floor);
	if (g->t_collect)
		mlx_delete_texture(g->t_collect);
	if (g->t_exit)
		mlx_delete_texture(g->t_exit);
}

void	ft_maharta(t_solong *g)
{
	if (g->t_player)
		mlx_delete_texture(g->t_player);
	if (g->t_wall)
		mlx_delete_texture(g->t_wall);
	if (g->t_wall_ul)
		mlx_delete_texture(g->t_wall_ul);
	if (g->t_wall_up)
		mlx_delete_texture(g->t_wall_up);
	if (g->t_wall_ur)
		mlx_delete_texture(g->t_wall_ur);
	if (g->t_wall_l)
		mlx_delete_texture(g->t_wall_l);
	if (g->t_wall_r)
		mlx_delete_texture(g->t_wall_r);
	if (g->t_wall_bl)
		mlx_delete_texture(g->t_wall_bl);
	if (g->t_wall_b)
		mlx_delete_texture(g->t_wall_b);
	if (g->t_wall_br)
		mlx_delete_texture(g->t_wall_br);
	ft_maharta_2(g);
}
