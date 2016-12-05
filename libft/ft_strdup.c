/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:06:31 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 12:23:55 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*cpy;
	int		lenght;

	lenght = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(*cpy) * lenght + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
