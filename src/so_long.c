/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:28 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/04 18:58:22 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_solong *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->row)
	{
		x = 0;
		while (x < g->col)
		{
			if (g->read_map[y][x] == '0')
				mlx_draw_texture(g->img, g->t_floor, (x * SPR), (y * SPR));
			else if (g->read_map[y][x] == '1')
				ft_draw_walls(g, x, y);
			else if (g->read_map[y][x] == 'P')
				ft_draw_player(g, g->x_pos, g->y_pos);
			else if (g->read_map[y][x] == 'C')
				mlx_draw_texture(g->img, g->t_collect, (x * SPR), (y * SPR));
			else if (g->read_map[y][x] == 'E')
				mlx_draw_texture(g->img, g->t_exit, (x * SPR), (y * SPR));
			x++;
		}
		y++;
	}
}

void	load_textures(t_solong *g)
{
	ft_load_player_textures(g);
	ft_load_walls_textures(g);
	g->t_floor = mlx_load_png("img/floor.png");
	if (!g->t_floor)
		ft_error(g, INVALID_TEXTURES);
	g->t_collect = mlx_load_png("img/collect.png");
	if (!g->t_collect)
		ft_error(g, INVALID_TEXTURES);
	g->t_exit = mlx_load_png("img/exit.png");
	if (!g->t_exit)
		ft_error(g, INVALID_TEXTURES);
}

void	init_game(t_solong *g)
{
	g->mlx = mlx_init(g->col * SPR, g->row * SPR, "so_long", true);
	g->img = mlx_new_image(g->mlx, g->col * SPR, g->row * SPR);
	mlx_image_to_window(g->mlx, g->img, 0, 0);
	load_textures(g);
	draw_map(g);
	mlx_key_hook(g->mlx, &ft_play, g);
	mlx_loop(g->mlx);
	ft_end_game(g);
}

int	main(int argc, char **argv)
{
	t_solong	*g;

	g = malloc(sizeof(t_solong));
	if (!g)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		ft_check_map(argv[1], g);
		init_game(g);
		ft_free(g);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_error(g, INVALID_ARGC);
		return (EXIT_FAILURE);
	}
}
