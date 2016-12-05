/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:45:10 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 13:32:02 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_blanks(const char *s)
{
	if (*s == ' ' || *s == '\n' || *s == '\f' || *s == '\t' || *s == '\v' ||
			*s == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *s)
{
	int			is_negative;
	int			nb;

	is_negative = 0;
	nb = 0;
	while (ft_check_blanks(s))
		s++;
	if (s[0] == 43)
		s++;
	else if (s[0] == 45)
	{
		is_negative = -1;
		s++;
	}
	while (*s != '\0' && (*s >= 48 && *s <= 57))
	{
		nb *= 10;
		nb += *s++ - 48;
	}
	if (is_negative)
		return (-nb);
	else
		return (nb);
}
