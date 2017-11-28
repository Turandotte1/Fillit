/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:14:50 by qugonzal          #+#    #+#             */
/*   Updated: 2017/05/17 16:33:16 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFIL_H
# define LIBFIL_H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct		s_tetrimino
{
	char				name;
	int				x[3];
	int				y[3];
	int				dim_x;
	int				dim_y;
}					t_tetri; 

typedef struct		s_map
{
	int				dim;
	char			**tab;
}					t_map;

char	**ft_reader(char *file);
void	ft_display_error(int message);
void	ft_display_map(char **tab);
int		ft_square(int block_nb);
int		main(int ac, char **av);
int		ft_checker(char **tab);
char	**ft_map_creation(int dim);
t_tetri	*ft_mk_tetri(char **tab, int elem_nbr);
int		ft_block_count(char **tab);
int		ft_check_fill(int x, int  y, t_map *map, t_tetri *tetri);
#endif
