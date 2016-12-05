/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:27:41 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/09 15:54:28 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;
	unsigned int	length;

	if (s != NULL)
	{
		i = 0;
		length = ft_strlen(s);
		string = ft_strnew(length);
		if (string)
		{
			while (i < length && *s != '\0')
			{
				string[i] = f(i, *s);
				s++;
				i++;
			}
			string[i] = '\0';
			return (string);
		}
	}
	return (NULL);
}
