/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:42:48 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/08 16:30:08 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cpy;
	size_t	i;

	cpy = dst;
	i = 0;
	while (*src != '\0' && i < len)
	{
		*dst = (char)*src;
		dst++;
		src++;
		i++;
	}
	while (i < len)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (cpy);
}
