/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:09:41 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/04 18:53:42 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_draw_player(t_solong *g, int x, int y)
{
	mlx_draw_texture(g->img, g->t_player, (x * SPR), (y * SPR));
}
