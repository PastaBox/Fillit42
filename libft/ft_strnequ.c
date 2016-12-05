/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:46:26 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/11 20:25:04 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (i < n || (*s1 != '\0' && *s2 != '\0'))
		{
			if (ft_strncmp(s1, s2, n) == 0)
				return (1);
			i++;
			s1++;
			s2++;
		}
	}
	return (0);
}
