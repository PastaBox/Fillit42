/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:20:21 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 13:35:19 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char*)src == c)
		{
			*(char*)dst = c;
			return (dst + 1);
		}
		*(char*)dst = *(char*)src;
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
