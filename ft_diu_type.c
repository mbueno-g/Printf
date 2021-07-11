/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::        */
/*   ft_diu_type.c									  :+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: mbueno-g <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2021/04/26 12:15:14 by mbueno-g		  #+#	#+#			      */
/*   Updated: 2021/07/11 15:29:19 by mbueno-g         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_diu_type(t_format *f, char c)
{
	int		n;
	char	*num;
	int		neg;
	char	sign;

	sign = '-';
	n = va_arg(f->ap, int);
	neg = 0;
	if (((n >= 0 && f->plus == 1) || (n >= 0 && f->spc)) && c != 'u')
		neg = 1;
	else if (n < 0 && n != INT_MIN && c != 'u')
		neg = 1;
	if (n >= 0 && f->spc == 1)
		sign = ' ';
	if (n >= 0 && f->plus == 1)
		sign = '+';
	if (c == 'u' && n < 0)
		num = ft_uitoa(UINT_MAX + n + 1);
	else
		num = ft_itoa(ft_abs(n));
	ft_print_num(f, num, neg, sign);
}

void	ft_print_num(t_format *f, char *num, int neg, char sign)
{
	int	len;
	int	i;

	len = ft_strlen((const char *)num);
	if (*num == '0' && (f->precision == 0 || f->spec == 0) && f->point == 1)
		len = 0;
	i = (f->precision < 0);
	if (f->precision < len)
		f->precision = len;
	if ((f->zero == 1 && !f->point) || (f->point == f->zero && i))
		f->count += ft_putnchar(sign, neg, 1);
	if (f->minus == -1 && f->width > f->precision && (f->zero != 1 || f->point) \
		&& (f->point != f->zero || !i))
		f->count += ft_putnchar(' ', f->width - f->precision - neg, 1);
	else if (f->minus == -1 && f->width > f->precision)
		f->count += ft_putnchar('0', f->width - f->precision - neg, 1);
	if ((f->point || f->zero == -1) && (f->point != f->zero || !i))
		f->count += ft_putnchar(sign, neg, 1);
	f->count += ft_putnchar('0', f->precision - len, 1);
	f->count += write(1, num, len);
	if (f->minus != -1 && ft_abs(f->width) > f->precision)
		f->count += ft_putnchar(' ', ft_abs(f->width) - f->precision - neg, 1);
	free(num);
}
