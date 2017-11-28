/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:26:50 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/16 16:33:52 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

static void		ft_dots_fill(char **map, int dim)
{
	int j;
	int k;

	k = 0;
	while (k < dim)
	{
		j = 0;
		while (j < dim)
			map[k][j++] = '.';
		map[k++][j] = '\0';
	}
	map[k] = 0;
}

int				ft_square(int block_nb)
{
	int		map_size;
	int		dim;

	dim = 0;
	map_size = block_nb * 4;
	while (dim * dim < map_size)
		dim++;
	return (dim);
}

char			**ft_map_creation(int dim)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char*) * (dim + 1))))
		return (NULL);
	while (dim > i)
	{
		if (!(map[i++] = (char*)ft_memalloc(sizeof(char) * (dim + 1))))
			return (NULL);
	}
	ft_dots_fill(map, dim);
	return (map);
}

void			ft_display_map(char **tab)
{
	while (*tab)
		ft_putendl(*tab++);
}
