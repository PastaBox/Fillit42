/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:07:17 by grleblan          #+#    #+#             */
/*   Updated: 2016/12/05 18:16:54 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char				**ft_init_mapping(char **src, int tetraminos)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < tetraminos)
	{
		j = 0;
		while (j < tetraminos)
		{
			src[i][j] = '.';
			j++;
		}
		src[i][j] = '\0';
		i++;
	}
	return (src);
}

void				ft_print_mapping(char **map)
{
	int				i;

	i = 0;
	while (map[i][0])
	{
		ft_putendl(map[i]);
		i++;
	}
}

int					ft_char(int tetraminos)
{
	int				cote;
	int				i;

	cote = 4 * tetraminos;
	i = 0;
	while (i * i < cote)
	{
		i++;
	}
	return (i);
}

char				**ft_mapping(int tetraminos)
{
	char			**map;
	char			**tmp;
	int				count;
	int				len;

	count = 0;
	map = NULL;
	tmp = NULL;
	len = ft_char(tetraminos);
	if (!(map = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tmp = map;
	while (count < len)
	{
		if (!(map[count] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		count++;
	}
	map = ft_init_mapping(map, len);
	map[len] = ft_strnew(0);
	return (tmp);
}
