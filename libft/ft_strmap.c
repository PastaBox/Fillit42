/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:32:28 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 12:27:52 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	i = 0;
	if (s != NULL)
	{
		string = (char *)malloc(sizeof(*string) * ft_strlen(s) + 1);
		if (string)
		{
			while (*s != '\0')
			{
				string[i] = f(*s++);
				i++;
			}
			string[i] = '\0';
			return (string);
		}
	}
	return (NULL);
}
