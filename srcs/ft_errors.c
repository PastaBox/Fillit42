/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:10:25 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/30 14:59:03 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_set_message_errors(char *message)
{
	if (message)
		ft_putendl_fd(message, 1);
	exit(-1);
}
