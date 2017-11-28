/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:08:26 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/16 16:33:58 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

static char		*ft_reader_open(char *file)
{
	int			fd;
	int			bytes_to_read;
	char		buffer[547];
	char		*buffer_copy;

	fd = open(file, O_RDONLY);
	ft_bzero(buffer, sizeof(buffer));
	bytes_to_read = read(fd, buffer, 546);
	if (bytes_to_read < 0)
		ft_display_error(2);
	if (close(fd) < 0)
		ft_display_error(2);
	buffer_copy = ft_strdup(buffer);
	return (buffer_copy);
}

static char		*ft_remplace(char *buffer_copy)
{
	size_t	i;
	char	c;

	i = 0;
	c = '!';
	while (buffer_copy[i++])
	{
		if (buffer_copy[i] == '\n' && buffer_copy[i + 1] == '\n')
			buffer_copy[i + 1] = c;
	}
	return (buffer_copy);
}

int				ft_block_count(char **tab)
{
	int		block_nb;

	block_nb = 0;
	while (tab[block_nb])
		block_nb++;
	if (block_nb > 26)
		ft_display_error(2);
	return (block_nb);
}

char			**ft_reader(char *file)
{
	char	*buffer_copy;
	char	**tab;
	char	c;

	c = '!';
	buffer_copy = ft_reader_open(file);
	ft_remplace(buffer_copy);
	tab = ft_strsplit(buffer_copy, c);
	ft_checker(tab);
	return (tab);
}
