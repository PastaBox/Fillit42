/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:13:39 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 12:26:03 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, (char*)s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
