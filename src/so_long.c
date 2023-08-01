/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:28 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/01 18:03:18 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_solong *g)
{
	g->mlx = mlx_init(g->col * SPR, g->row * SPR, "so_long", false);
	mlx_loop(g->mlx);
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_solong	*g;

	atexit(leaks);
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
