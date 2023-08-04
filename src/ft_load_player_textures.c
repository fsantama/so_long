/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:04:06 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/03 19:38:43 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_load_player_textures(t_solong *g)
{
	g->t_player = mlx_load_png("img/player.png");
	if (!g->t_player)
		ft_error(g, INVALID_TEXTURES);
}
