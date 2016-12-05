/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:48:41 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 13:35:31 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	char		*source;

	destination = (char*)dst;
	source = (char*)src;
	i = n;
	while (i-- > 0)
		destination[i] = source[i];
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		ft_memcpy_rev(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
