/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:07:49 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/05/07 23:16:42 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi2(const char *str, t_format *format)
{
	int	i;
	int	cont;
	int	num;

	i = 0;
	cont = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		cont = -cont && (str[i] == '-');
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * cont > 214748364 && str[i] - '0' > 7)
			return (-1);
		if (num * cont < -214748364 && str[i] - '0' >= 8)
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	format->n = i - 1;
	return (num * cont);
}
