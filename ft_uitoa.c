/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:09:24 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/05/11 18:57:51 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_u_len(unsigned long int num)
{
	int	len;

	len = 0;
	if (num < 10)
		return (1);
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned long int num)
{
	char	*str;
	int		len;

	len = ft_u_len(num);
	str = ft_calloc(len + 1, sizeof(char));
	if (len == 0)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		len--;
		num = num / 10;
	}
	return (str);
}
