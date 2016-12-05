/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:45:00 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/11 13:22:58 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		j;
	int		i;
	char	*str;

	j = 0;
	i = 0;
	if (s != NULL && len > 0)
	{
		i = start;
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		if (ft_strlen(s) < (start + len))
			return (NULL);
		while (s[i] != '\0' && (i < ((int)start + (int)len)))
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
