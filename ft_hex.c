/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:15:23 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 15:35:27 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex_len(size_t nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	recursive_hex_pos(size_t nbr, char *base, t_format *format)
{
	if (nbr >= 16)
	{
		recursive_hex_pos(nbr / 16, base, format);
		format->count += write(1, &base[nbr % 16], 1);
	}
	else
		format->count += write(1, &base[nbr], 1);
}
