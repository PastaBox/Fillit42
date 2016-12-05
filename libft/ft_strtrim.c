/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:21:33 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 13:33:18 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int			count;
	int			length;
	char		*str;

	if (s)
	{
		while (*s == 32 || *s == '\n' || *s == '\t')
			s++;
		if (*s == '\0')
			return (ft_strnew(1));
		length = ft_strlen(s) - 1;
		while (s[length] == 32 || s[length] == '\n' || s[length] == '\t')
			length--;
		str = ft_strnew(length + 1);
		count = -1;
		if (str == NULL)
			return (NULL);
		while (++count <= length)
			str[count] = s[count];
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
