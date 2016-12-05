/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:43:21 by grleblan          #+#    #+#             */
/*   Updated: 2016/11/30 12:22:53 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris			*ft_create(t_tetris *list, int a, char *buffer, int start)
{
	t_tetris		*llist;
	t_tetris		*tmp;
	char			**tabl;

	tmp = list;
	tabl = NULL;
	llist = NULL;
	if (!(llist = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	tabl = ft_alloc(buffer, start);
	llist->str = tabl;
	llist->alpha = a;
	llist->tab.tab_y = ft_check_block_y(llist);
	llist->tab.tab_x = ft_check_block_x(llist);
	llist->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = llist;
	return (llist);
}

char				**ft_alloc(char *buffer, int start)
{
	char			**array;
	int				i;

	i = 0;
	array = NULL;
	if (!(array = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(array[i] = ft_strsub(buffer, start, 5)))
			return (NULL);
		start += 5;
		i++;
	}
	array[4] = ft_strnew(1);
	return (array);
}

t_tetris			*ft_solver(char *buffer, int tetriminos)
{
	int				i;
	t_tetris		*tmp;
	t_tetris		*lst;
	int				al;
	char			**tabl;

	tmp = NULL;
	i = 0;
	al = 65;
	lst = NULL;
	if (!(tmp = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	lst = tmp;
	tabl = ft_alloc(buffer, 0);
	tmp->str = tabl;
	tmp->alpha = al;
	tmp->tab.tab_y = ft_check_block_y(tmp);
	tmp->tab.tab_x = ft_check_block_x(tmp);
	tmp->next = NULL;
	while (++i < tetriminos && al++ != 26)
		tmp = ft_create(tmp, al, buffer, 21 * i);
	ft_strdel(tabl);
	return (lst);
}
