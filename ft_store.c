/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:20:40 by qugonzal          #+#    #+#             */
/*   Updated: 2017/05/16 17:57:44 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libfil.h"

void		save_tetri(t_tetri *tetri, char *s, int i)
{
	int		nb;
	int		x_first;
	int		y_first;

	nb = 0;
	x_first = i % 5;
	y_first = i / 5;
	while (nb < 3)
	{
		i++;
		if (s[i] == '#')
		{
			tetri->x[nb] = i % 5 - x_first;
			tetri->y[nb] = i / 5 - y_first;
			nb++;
		}
	}
}

void		find_1st_block(char *s, t_tetri *tetri)
{
	int i;

	i = 0;
	while (s[i] != '#' && s[i])
		i++;
	save_tetri(tetri, &s[0], i);
}

void		find_dimension(int *tab, int *dim)
{
	int i;

	i = 0;
	*dim = 0;
	while (i != 3)
	{
		if (tab[i] < 0)
		{
			if (tab[i] < *dim)
				*dim = tab[i];
		}
		if (tab[i] > *dim)
			*dim = tab[i];
		i++;
	}
}

t_tetri		*ft_mk_tetri(char **tab, int elem_nbr)
{
	t_tetri		*elem;
	t_tetri		tetri;
	char		name;
	int			n;

	if (!(elem = malloc(sizeof(elem_nbr))))
		return (NULL);
	name = 'A';
	n = 0;
	while (n < elem_nbr)
	{
		printf("%s\n", tab[n]);
		tetri.name = name;
		find_1st_block(tab[n], &tetri);
		find_dimension(tetri.x, &tetri.dim_x);
		find_dimension(tetri.y, &tetri.dim_y);
		elem[n] = tetri;
		name++;
		n++;
	}
	return (elem);
}
