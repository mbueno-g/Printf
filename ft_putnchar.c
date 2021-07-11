/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:08:48 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/05/11 18:41:44 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnchar(char c, int n, int fd)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += (int) write(fd, &c, 1);
		n--;
	}
	return (count);
}
