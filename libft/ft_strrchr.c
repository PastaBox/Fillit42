/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:57:12 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/06 15:10:14 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occurence;

	last_occurence = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_occurence = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_occurence);
}
