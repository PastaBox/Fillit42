/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:57:03 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 11:17:20 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_countchars(long n)
{
	int				counter;

	counter = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char				*ft_itoa(int n)
{
	size_t			length;
	long			x;
	char			is_neg;
	char			*str;

	x = n;
	is_neg = (n < 0 ? 1 : 0);
	length = ft_countchars(x);
	str = ft_strnew(length + is_neg);
	if (str == NULL)
		return (NULL);
	if (is_neg)
	{
		x = -x;
		str[0] = '-';
	}
	while (length > 0)
	{
		str[length + is_neg - 1] = (x % 10) + '0';
		length--;
		x /= 10;
	}
	return (str);
}
