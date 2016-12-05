/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:12:41 by grleblan          #+#    #+#             */
/*   Updated: 2016/11/30 13:11:34 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			**ft_reset_map(t_tetris *list, int y, int x, char **map)
{
	int			i;
	int			*taby;
	int			*tabx;
	t_tetris	*llist;

	i = 1;
	llist = list;
	taby = llist->tab.tab_y;
	tabx = llist->tab.tab_x;
	map[y][x] = '.';
	while (i < 4)
	{
		y += taby[i] - taby[i - 1];
		x += tabx[i] - tabx[i - 1];
		map[y][x] = '.';
		i++;
	}
	return (map);
}

char			**ft_place_piece(t_tetris *list, int y, int x, char **map)
{
	int			i;
	int			*taby;
	int			*tabx;
	t_tetris	*llist;

	i = 1;
	llist = list;
	taby = llist->tab.tab_y;
	tabx = llist->tab.tab_x;
	map[y][x] = list->alpha;
	while (i < 4)
	{
		y += taby[i] - taby[i - 1];
		x += tabx[i] - tabx[i - 1];
		map[y][x] = list->alpha;
		i++;
	}
	return (map);
}

int				ft_check_valid(t_tetris *list, int y, int x, char **map)
{
	int			*taby;
	int			*tabx;
	int			posx;
	int			posy;
	int			i;

	i = 1;
	posx = x;
	posy = y;
	taby = list->tab.tab_y;
	tabx = list->tab.tab_x;
	while (map[y][x] == '.' && i < 4)
	{
		y += taby[i] - taby[i - 1];
		x += tabx[i] - tabx[i - 1];
		i++;
	}
	if (i == 4 && map[y][x] == '.')
	{
		map = ft_place_piece(list, posy, posx, map);
		return (1);
	}
	return (0);
}

int				ft_resolution(t_tetris *list, char **map, int size)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	if (list == NULL)
		return (1);
	while (y < size)
	{
		while (x < size)
		{
			if (ft_check_valid(list, y, x, map))
			{
				if (ft_resolution(list->next, map, size))
					return (1);
				else
					map = ft_reset_map(list, y, x, map);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char			**ft_recur_map(t_tetris *list, int tetraminos)
{
	char		**map;
	char		**tmp;
	int			size;
	int			i;

	i = 0;
	size = ft_char(tetraminos);
	map = ft_mapping(tetraminos);
	tmp = map;
	while (!(ft_resolution(list, map, size)))
	{
		map = NULL;
		ft_strdel(map);
		size++;
		tetraminos++;
		map = ft_mapping(tetraminos);
	}
	ft_print_mapping(map);
	ft_strdel(map);
	free(list);
	return (tmp);
}
