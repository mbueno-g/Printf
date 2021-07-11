/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:57:23 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 15:35:21 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_check_point(const char *str, t_format *f);

const char	*ft_check_format(const char *str, t_format *f)
{
	if (*str == '-')
		f->minus = 1;
	else if (*str == '+')
		f->plus = 1;
	else if (*str == ' ')
		f->spc = 1;
	else if (*str == '#')
		f->hash = 1;
	if (*str == '0' && f->zero == -1)
		f->zero = 1;
	else if (*str == '*')
		f->width = va_arg(f->ap, int);
	else if (*str >= '0' && *str <= '9')
	{
		f->width = ft_atoi2(str, f);
		str = str + f->n;
	}
	str = ft_check_point(str, f);
	if (*str == 'l')
		f->len = 'l';
	else if (*str == 'h')
		f->len = 'h';
	str++;
	return (str);
}

const char	*ft_check_point(const char *str, t_format *f)
{
	if (*str == '.')
	{
		f->point = 1;
		if (!ft_strchr(SPECIFIERS, *(str + 1)))
		{
			str++;
			if (*str == '*')
			{
				f->precision = va_arg(f->ap, int);
				f->spec = 1;
			}
			else if (*str >= '0' && *str <= '9')
			{
				f->precision = ft_atoi2(str, f);
				f->spec = 1;
				str = str + f->n;
			}
		}
	}
	if (f->width < 0)
		f->minus = 1;
	return (str);
}
