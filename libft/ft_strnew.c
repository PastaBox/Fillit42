/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:19:31 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/08 11:26:31 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(*new) * size + 1);
	if (!new)
		return (NULL);
	else
	{
		while (i < size)
		{
			new[i] = 0;
			i++;
		}
		new[i] = 0;
		return (new);
	}
}
