/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:53:31 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/10 19:10:32 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_type(const char *str, t_format *f)
{
	if (*str == 's')
		ft_s_type(f);
	else if (*str == 'c')
		ft_c_type(f, 0);
	else if (*str == '%')
		ft_c_type(f, 1);
	else if (*str == 'd' || *str == 'i')
		ft_diu_type(f, 'd');
	else if (*str == 'u')
		ft_diu_type(f, 'u');
	else if (*str == 'x' && f->hash == 1)
		ft_p_hash_type(f, 0);
	else if (*str == 'X' && f->hash == 1)
		ft_p_hash_type(f, 1);
	else if (*str == 'x')
		ft_x_type(f, 0);
	else if (*str == 'X')
		ft_x_type(f, 1);
	else if (*str == 'p')
		ft_p_type(f);
}
