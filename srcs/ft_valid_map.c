/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:40:39 by fciprian          #+#    #+#             */
/*   Updated: 2016/12/02 11:13:34 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				ft_check_empty_map(char *buffer)
{
	int			index;
	int			nb_empty;
	int			nb_blocs;

	index = 0;
	nb_empty = 0;
	nb_blocs = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '.')
			nb_empty++;
		if (buffer[index] == '#')
			nb_blocs++;
		if (buffer[index] == '\n' && buffer[index + 1] == '\n')
		{
			nb_empty = 0;
			nb_blocs = 0;
		}
		index++;
	}
	if (nb_empty == 16 || nb_blocs == 16)
		return (0);
	else
		return (1);
}

int				ft_return_contact(char *s, int i, int contact, int tetris)
{
	while (s[++i] != '\0')
	{
		if (s[i] == '#' && s[i + 1] == '#')
			contact++;
		if (s[i] == '#' && s[i - 1] == '#')
			contact++;
		if (s[i] == '#' && s[i + 5] == '#')
			contact++;
		if (s[i] == '#' && s[i - 5] == '#')
			contact++;
		if (contact >= 6)
		{
			contact = 0;
			tetris++;
		}
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			contact = 0;
			if (tetris != 1)
				return (0);
			tetris = 0;
		}
	}
	return (ft_tetris_norme(tetris));
}

int				ft_check_contact(char *s)
{
	int			i;
	int			contact;
	int			tetris;

	i = -1;
	contact = 0;
	tetris = 0;
	if (ft_return_contact(s, i, contact, tetris))
		return (1);
	return (0);
}

int				ft_check_chars(char *buffer)
{
	int			index;
	int			blocs;

	index = 0;
	blocs = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] != '\n' && buffer[index] != '#' && buffer[index] !=
				'.')
			return (-1);
		if (ft_isalnum(buffer[index]))
			return (0);
		if (buffer[index] == '#')
			blocs++;
		if (buffer[index] == '\n' && buffer[index + 1] == '\n')
			blocs = 0;
		if (blocs > 4 || buffer[index] == 32)
			return (0);
		index++;
	}
	return (1);
}

int				ft_valid_map(char *buffer)
{
	if (ft_check_chars(buffer) != 1)
		return (0);
	if (ft_check_empty_map(buffer) != 1)
		return (-1);
	if (ft_check_contact(buffer) != 1)
		return (-2);
	return (1);
}
