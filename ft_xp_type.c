/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xp_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:36:25 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 15:19:10 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_p_hash_type(t_format *f, int i)
{
	int		len;
	size_t	n;
	int		j;

	n = (size_t) va_arg(f->ap, void *);
	len = ft_hex_len(n);
	j = (f->precision < 0);
	if (n == 0 && (f->precision == 0 || f->spec == 0) && f->point == 1)
		len = 0;
	if (f->precision < len)
		f->precision = len;
	if (f->minus == -1 && f->width > f->precision && \
			(f->zero != 1 || f->point) && (f->point != f->zero || !j))
		f->count += ft_putnchar(' ', f->width - f->precision - 2 * (n != 0), 1);
	ft_printf_p_hash(f, j, n, i);
}

void	ft_printf_p_hash(t_format *f, int j, size_t n, int i)
{
	char	*base;
	int		len;

	len = ft_hex_len(n);
	base = "0123456789abcdef";
	if (i == 1)
		base = "0123456789ABCDEF";
	if (n != 0)
	{
		if (i == 0)
			f->count += write(1, "0x", 2);
		else if (i == 1)
			f->count += write(1, "0X", 2);
	}
	len *= !(n == 0 && (f->precision == 0 || f->spec == 0) && f->point == 1);
	if (f->minus == -1 && f->width > f->precision \
		&& ((f->zero == 1 && !f->point) || (f->point == f->zero && j)))
		f->count += ft_putnchar('0', f->width - f->precision - 2 * (n != 0), 1);
	if (len < f->precision)
		f->count += ft_putnchar('0', f->precision - len, 1);
	if (len)
		recursive_hex_pos(n, base, f);
	f->width = ft_abs(f->width);
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', f->width - f->precision - 2 * (n != 0), 1);
}

void	ft_p_type(t_format *f)
{
	int		len;
	size_t	n;

	n = (size_t) va_arg(f->ap, void *);
	len = ft_hex_len(n);
	if (n == 0 && f->width == 2)
		len = 2;
	if (n == 0 && (f->precision == 0 || f->spec == 0) && f->point == 1)
		len = 0;
	if (f->precision < len)
		f->precision = len;
	if (f->minus == -1 && f->width > f->precision)
		f->count += ft_putnchar(' ', f->width - f->precision - 2, 1);
	f->count += write(1, "0x", 2);
	if (len < f->precision)
		f->count += ft_putnchar('0', f->precision - len, 1);
	if (len)
	{
		if (n == 0)
			f->count += ft_putnchar('0', 1, 1);
		else
			recursive_hex_pos(n, "0123456789abcdef", f);
	}
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', ft_abs(f->width) - f->precision - 2, 1);
}

void	ft_x_type(t_format *f, int m)
{
	char			*base;
	int				len;
	unsigned int	n;
	int				i;

	n = va_arg(f->ap, unsigned int);
	len = ft_hex_len(n);
	i = (f->precision < 0);
	base = "0123456789abcdef";
	if (m == 1)
		base = "0123456789ABCDEF";
	if (n == 0 && (f->precision == 0 || f->spec == 0) && f->point == 1)
		len = 0;
	if (f->precision < len)
		f->precision = len;
	if (f->minus == -1 && f->width > f->precision && \
			(f->zero != 1 || f->point) && (f->point != f->zero || !i))
		f->count += ft_putnchar(' ', f->width - f->precision, 1);
	else if (f->minus == -1 && f->width > f->precision)
		f->count += ft_putnchar('0', f->width - f->precision, 1);
	f->count += ft_putnchar('0', f->precision - len, 1);
	if (len)
		recursive_hex_pos(n, base, f);
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', ft_abs(f->width) - f->precision, 1);
}
