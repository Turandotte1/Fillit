/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:02:24 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/16 16:33:44 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

static int		ft_adjustment_check(char *str)
{
	int		adj_count;
	int		index;

	adj_count = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '#')
		{
			if (str[index + 1] == '#' && ((index + 1) <= 20))
				adj_count++;
			if (str[index - 1] == '#' && ((index - 1) >= 0))
				adj_count++;
			if (str[index + 5] == '#' && ((index + 5) <= 20))
				adj_count++;
			if (str[index - 5] == '#' && ((index - 5) >= 0))
				adj_count++;
		}
	}
	return (adj_count == 6 || adj_count == 8);
}

static int		ft_char_check(char *str)
{
	size_t	index;
	int		dot;
	int		hash;
	int		nl;

	index = -1;
	dot = 0;
	hash = 0;
	nl = 0;
	while (str[++index])
	{
		if (index % 5 && str[index] == '\n')
			nl++;
		else if (str[index] == '.')
			dot++;
		else if (str[index] == '#')
			hash++;
	}
	return (dot == 12 && hash == 4 && nl == 4);
}

int				ft_checker(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i] != NULL)
	{
		if (!(ft_char_check(tab[i])))
			ft_display_error(2);
		else if (!(ft_adjustment_check(tab[i])))
			ft_display_error(2);
	}
	return (42);
}
