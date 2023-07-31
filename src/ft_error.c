/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:01 by fsantama          #+#    #+#             */
/*   Updated: 2023/07/31 16:24:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(t_solong *g)
{
	int	i;

	i = 0;
	if (g->read_map)
	{
		while (g->read_map[i])
			free(g->read_map[i++]);
		free(g->read_map);
		i = 0;
		while (g->copy_map[i])
			free(g->copy_map[i++]);
		free(g->copy_map);
	}
	free(g);
}

void	ft_error(t_solong *g, char *error)
{
	(void) g;
	ft_putstr_fd("Error. ", 2);
	ft_putstr_fd(error, 2);
	ft_free(g);
	exit(EXIT_FAILURE);
}
