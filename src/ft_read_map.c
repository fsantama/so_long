/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:54:40 by fsantama          #+#    #+#             */
/*   Updated: 2023/07/25 12:52:33 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_read_map(t_solong *g)
{
	char	*line;
	char	*total_read;

	line = NULL;
	total_read = NULL;
	while (1)
	{
		line = get_next_line(g->fd_map);
		if (line == 0)
			break ;
		total_read = ft_strjoinfree(total_read, line);
		free(line);
	}
	if (total_read == 0 || total_read[0] == '\n')
		ft_error(g, EMPTY_MAP);
	g->read_map = ft_split(total_read, '\n');
	g->copy_map = ft_split(total_read, '\n');
	free(total_read);
	close(g->fd_map);
}
