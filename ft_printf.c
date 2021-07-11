/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:36:57 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/10 19:17:37 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset_struct(t_format *f)
{
	f->n = 0;
	f->minus = -1;
	f->width = 0;
	f->precision = -1;
	f->spec = 0;
	f->point = 0;
	f->zero = -1;
	f->plus = 0;
	f->spc = 0;
	f->hash = 0;
	f->len = ' ';
}

int	ft_printf(const char *str, ...)
{
	t_format	f;

	va_start(f.ap, str);
	f.count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_reset_struct(&f);
			while (*str && ft_strchr("0123456789-.*+ #lh", *str))
				str = ft_check_format(str, &f);
			if (*str && ft_strchr(SPECIFIERS, *str))
				ft_check_type(str, &f);
		}
		else
			f.count += write(1, str, 1);
		if (*str)
			str++;
	}
	va_end(f.ap);
	return (f.count);
}
