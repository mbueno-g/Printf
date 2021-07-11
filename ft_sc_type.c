/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sc_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:15:48 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/10 18:44:34 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_c_type(t_format *f, int n)
{
	char	c;

	if (n == 0)
		c = va_arg(f->ap, int);
	else
		c = '%';
	f->precision = 1;
	if (f->minus == -1 && f->width > f->precision && f->zero == 1 && !f->point)
		f->count += ft_putnchar('0', f->width - f->precision, 1);
	else if (f->minus == -1 && f->width > f->precision)
		f->count += ft_putnchar(' ', f->width - f->precision, 1);
	f->count += write(1, &c, 1);
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', ft_abs(f->width) - f->precision, 1);
}

void	ft_s_type(t_format *f)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(f->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = (f->precision < 0);
	if (f->precision == -1 && f->point == 1 && !f->spec)
		f->precision = 0;
	if (f->precision <= -1 || f->precision > len)
		f->precision = len;
	if (f->minus == -1 && f->width > f->precision && (f->zero != 1 || f->point) \
		&& (f->point != f->zero || !i))
		f->count += ft_putnchar(' ', f->width - f->precision, 1);
	else if (f->minus == -1 && f->width > f->precision)
		f->count += ft_putnchar('0', f->width - f->precision, 1);
	f->count += write(1, str, f->precision);
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', ft_abs(f->width) - f->precision, 1);
}
