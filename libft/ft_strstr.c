/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:03:31 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/08 16:48:48 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)big;
	i = 0;
	if (!*little)
		return (str);
	while (str[i])
	{
		j = 0;
		while (little[j] == str[i + j])
		{
			if (little[j + 1] == 0)
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
