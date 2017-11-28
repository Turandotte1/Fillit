/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:31:38 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/17 16:47:11 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

void	ft_display_error(int message)
{
	if (message == 1)
		ft_putendl("usage: input file");
	else if (message == 2)
		ft_putendl("error");
	exit (0);
}

int		main(int ac, char **av)
{
	t_tetri		*pika_ili;
	t_map		map;
	int 		j = 0;
	int		h = 0;

	if (ac != 2)
		ft_display_error(1);
	map.tab = ft_reader(av[1]);
	map.dim = ft_square(ft_block_count(map.tab));
	pika_ili = ft_mk_tetri(map.tab, 8);
	printf("dim_x = %d\n", pika_ili->dim_x);
	while (j < 8)
	{	
		h = 0;
		printf("%s\n", "debut du while");
		printf("%c\n", pika_ili[j].name);
		while (h < 3)
		{
			printf("x=%d\n", pika_ili[j].x[h]);
			h++;
		}
		h = 0;
		while (h < 3)
		{
			printf("y=%d\n", pika_ili[j].y[h]);
			h++;
		}
		j++;
		printf("dim_x = %d\n", pika_ili->dim_x);
	}
	printf("map.dim = %d\n", map.dim);
	printf("dim_x = %d\n", pika_ili->dim_x);
	printf("checkfill = %d\n", ft_check_fill(0, 0, &map, pika_ili));
	map.tab = ft_map_creation(map.dim);
	ft_display_map(map.tab);
	return (0);
}
