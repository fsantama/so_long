/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:04:06 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/06 17:43:23 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_load_player_textures(t_solong *g)
{
	g->t_player = mlx_load_png("img/player.png");
	if (!g->t_player)
		ft_error(g, INVALID_TEXTURES);
}
