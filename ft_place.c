/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:25:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/05/17 16:47:14 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_check_fill(int x, int y, t_map *map, t_tetri *tetri)
{
	if (x + tetri->dim_x >= map->dim)
		return (1);
	if (y + tetri->dim_y >= map->dim)
		return (2);
	if (map->tab[x + tetri->x[0]][y + tetri->y[0]] == '#' ||
			map->tab[x + tetri->x[1]][y + tetri->y[1]] == '#' ||
			map->tab[x + tetri->x[2]][y + tetri->y[2]] == '#' ||
			x + tetri->dim_x < 0)
		return (3);
	return (0);
}

int		ft_place(int x, int y, t_map *map, t_tetri *tetri)
{
	int nb;

	nb = 0;
	map->tab[y][x] = tetri->name;
	while (nb < 3)
	{
		map->tab[y + tetri->y[nb]][x + tetri->x[nb]] = tetri->name;
		nb++;
	}
	return (1);
}

int		ft_find_place(t_map *map, t_tetri *tetri)
{
	int x;
	int y;
	int chk;

	y = -1;
	while (++y < map->dim)
	{
		x = -1;
		while (++x < map->dim)
		{
			if (map->tab[y][x] == '.')
			{
				chk = ft_check_fill(x, y, map, tetri);
				if (chk == 1)
					break ;
				if (chk == 2)
					return (0);
				if (!chk)
					return (ft_place(x, y, map, tetri));
			}
		}
	}
	return (0);
}
