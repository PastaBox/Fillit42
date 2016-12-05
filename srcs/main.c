/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:30:00 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/30 11:04:07 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_tetris_norme(int tetris)
{
	if (tetris == 0)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	int		file_descriptor;

	if (argc != 2)
	{
		ft_set_message_errors("Usage: ./fillit [map file]");
		return (-1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor < 0)
		ft_set_message_errors("error");
	ft_gestion(file_descriptor);
	close(file_descriptor);
	return (0);
}
