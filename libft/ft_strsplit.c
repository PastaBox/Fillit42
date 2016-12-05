/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:59:13 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/12 13:33:31 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(int c, char const *s)
{
	int			words;
	int			i;

	i = 0;
	words = 0;
	while (*s != '\0')
	{
		if (words == 1 && *s == c)
			words = 0;
		if (words == 0 && *s != c)
		{
			i++;
			words = 1;
		}
		s++;
	}
	return (i);
}

static	int		ft_count_length(char const *s, char c)
{
	int			length;

	length = 0;
	while (*s != '\0' && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	int			index;
	int			words;
	char		**array;

	if (s != NULL && c)
	{
		index = 0;
		words = ft_count_words(c, s);
		array = (char**)malloc(sizeof(*array) * ft_count_words(c, s) + 1);
		if (array == NULL)
			return (NULL);
		while (words-- > 0)
		{
			while (*s != '\0' && *s == c)
				s++;
			array[index] = ft_strsub(s, 0, ft_count_length(s, c));
			if (array[index] == NULL)
				return (NULL);
			s += ft_count_length(s, c);
			index++;
		}
		array[index] = 0;
		return (array);
	}
	return (NULL);
}
