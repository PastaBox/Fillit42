/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:20:15 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 10:22:51 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	void	*tmp;

	list = *alst;
	tmp = NULL;
	while (list != NULL)
	{
		tmp = list->next;
		ft_lstdelone(&list, del);
		list = tmp;
	}
	*alst = NULL;
}
