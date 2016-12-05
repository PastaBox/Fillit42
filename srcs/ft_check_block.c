/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:53 by grleblan          #+#    #+#             */
/*   Updated: 2016/11/30 15:03:51 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			*ft_malloc_tab(int *tab)
{
	tab = NULL;
	if (!(tab = (int*)malloc(sizeof(int) * (5))))
		return (NULL);
	return (tab);
}

int			*ft_check_block_x(t_tetris *list)
{
	char	**tmp;
	int		*tab1;
	int		x;
	int		y;
	int		count;

	y = -1;
	count = 0;
	tab1 = NULL;
	tab1 = ft_malloc_tab(tab1);
	tmp = list->str;
	while (tmp[++y][0] != '\0')
	{
		x = -1;
		while (tmp[y][++x] != '\n')
		{
			if (tmp[y][x] == '#')
			{
				tab1[count] = x;
				count++;
			}
		}
	}
	tab1[4] = 0;
	return (tab1);
}

int			*ft_check_block_y(t_tetris *list)
{
	char	**tmp;
	int		*tab1;
	int		x;
	int		y;
	int		count;

	y = -1;
	count = 0;
	tab1 = NULL;
	tab1 = ft_malloc_tab(tab1);
	tmp = list->str;
	while (tmp[++y][0] != '\0')
	{
		x = -1;
		while (tmp[y][++x] != '\n')
		{
			if (tmp[y][x] == '#' && count < 4)
			{
				tab1[count] = y;
				count++;
			}
		}
	}
	tab1[4] = 0;
	return (tab1);
}
