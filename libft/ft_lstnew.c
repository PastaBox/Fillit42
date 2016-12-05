/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:53:14 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 14:16:44 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*tmp;
	size_t	size;

	tmp = NULL;
	size = 0;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		tmp = ft_memalloc(content_size);
		size = content_size;
		ft_memcpy(tmp, content, size);
		list->content = tmp;
		list->content_size = size;
	}
	list->next = NULL;
	return (list);
}
