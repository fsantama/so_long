/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_walls_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:41:19 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/06 18:12:27 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_load_walls_textures_3(t_solong *g)
{
	g->t_wall_br = mlx_load_png("img/wall_br.png");
	if (!g->t_wall_br)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
}

void	ft_load_walls_textures_2(t_solong *g)
{
	g->t_wall_l = mlx_load_png("img/wall_l.png");
	if (!g->t_wall_l)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_r = mlx_load_png("img/wall_r.png");
	if (!g->t_wall_r)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_bl = mlx_load_png("img/wall_bl.png");
	if (!g->t_wall_bl)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_b = mlx_load_png("img/wall_b.png");
	if (!g->t_wall_b)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	ft_load_walls_textures_3(g);
}

void	ft_load_walls_textures(t_solong *g)
{
	g->t_wall = mlx_load_png("img/wall.png");
	if (!g->t_wall)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_ul = mlx_load_png("img/wall_ul.png");
	if (!g->t_wall_ul)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_up = mlx_load_png("img/wall_up.png");
	if (!g->t_wall_up)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	g->t_wall_ur = mlx_load_png("img/wall_ur.png");
	if (!g->t_wall_ur)
	{
		ft_maharta(g);
		ft_error(g, INVALID_TEXTURES);
	}
	ft_load_walls_textures_2(g);
}
