/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:56:45 by fciprian          #+#    #+#             */
/*   Updated: 2016/12/02 11:12:22 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_check_empty_separator(char *buffer)
{
	size_t		length;
	size_t		size;

	size = 21;
	length = ft_strlen(buffer);
	while (size < length)
	{
		if (buffer[size - 1] != '\n')
			ft_set_message_errors("error");
		size = size + 21;
	}
}

void			ft_check_length(int length)
{
	if (length <= 0)
		ft_set_message_errors("error");
	if ((length + 1) % (TETRIMINOS_MAX_LENGHT + 1) != 0)
		ft_set_message_errors("error");
}

int				ft_check_pattern(char *str)
{
	size_t		index;
	int			tetriminos;
	size_t		length;

	index = -1;
	tetriminos = 1;
	length = ft_strlen(str);
	while (++index < length && (str[index] == '.' || str[index] == '#' ||
				str[index] == '\n'))
	{
		if (str[index] == '\n' && str[index + 1] == '\n')
			tetriminos++;
	}
	return (tetriminos);
}

int				ft_reader(int file_descriptor, char *buffer)
{
	int			reading;

	reading = read(file_descriptor, buffer, BUFFER_SIZE);
	if (reading < 0)
		ft_set_message_errors("error");
	return (reading);
}

void			ft_gestion(int file_descriptor)
{
	int			reading;
	int			tetriminos;
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	t_tetris	*list;

	i = 0;
	reading = ft_reader(file_descriptor, buffer);
	ft_check_length(reading);
	ft_check_empty_separator(buffer);
	tetriminos = ft_check_pattern(buffer);
	if (ft_valid_map(buffer) > 0)
	{
		if (tetriminos <= 26)
		{
			list = ft_solver(buffer, tetriminos);
			ft_recur_map(list, tetriminos);
		}
		else
			ft_set_message_errors("error");
	}
	else
		ft_set_message_errors("error");
}
