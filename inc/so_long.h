/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:25:09 by fsantama          #+#    #+#             */
/*   Updated: 2023/07/31 18:44:12 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define INVALID_ARGC "Enter a single map as argument\n"
# define INVALID_NAME_MAP "Enter as argument a map with extension .ber\n"
# define EMPTY_MAP "Map is empty\n"
# define NO_QUADRILATERAL_MAP "Map is not a quadrilateral\n"
# define LIMIT_MAP "Map is not closed\n"
# define INVALID_FD "Map does not exist or you do not have the permissions\n"
# define INVALID_CHAR "Map contains invalid characteres\n"
# define INVALID_OBJECTS "Invalid numbers of player, collect or exit.\n"
# define INVALID_SOLUTION "Map has no solution\n"

typedef struct s_solong
{
	char	*map;
	int		fd_map;
	char	**read_map;
	char	**copy_map;
	int		col;
	int		row;
	int		n_player;
	int		n_collect;
	int		n_exit;
	int		x_pos;
	int		y_pos;
}	t_solong;

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *read_line);
char	*ft_get_line(char *read_line);
char	*ft_get_new_line(char *read_line);
char	*ft_strchrnew(char *s, int c);
char	*ft_strjoinfree(char *s1, char *s2);
int		ft_strlennew(char *s);
int		main(int argc, char **argv);
void	ft_check_map(char *map, t_solong *g);
void	leaks(void);
void	ft_error(t_solong *g, char *error);
void	ft_read_map(t_solong *g);
void	ft_free(t_solong *g);
void	ft_check_solution(t_solong *g);

#endif
