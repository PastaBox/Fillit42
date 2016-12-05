/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:57:28 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/11 21:35:22 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char*)big;
	if (!*little)
		return (str);
	while (str[i])
	{
		j = 0;
		while (little[j] == str[i + j] && n > 0)
		{
			if (little[j + 1] == 0)
				return (str + i);
			j++;
			n--;
		}
		i++;
	}
	return (NULL);
}
