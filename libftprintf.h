/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <mbueno-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:14:01 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 16:08:24 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		count;
	int		minus;
	int		width;
	int		precision;
	int		spec;
	int		point;
	int		zero;
	int		n;
	va_list	ap;
	int		plus;
	int		spc;
	int		hash;
	char	len;
}				t_format;

# define SPECIFIERS "cspdiuxX%"

int			ft_printf(const char *str, ...);
void		ft_reset_struct(t_format *f);
const char	*ft_check_format(const char *str, t_format *f);
void		ft_check_type(const char *str, t_format *f);
void		ft_s_type(t_format *f);
void		ft_c_type(t_format *f, int n);
void		ft_diu_type(t_format *f, char c);
void		ft_print_num(t_format *f, char *num, int neg, char sign);
void		ft_x_type(t_format *f, int m);
void		ft_p_type(t_format *f);
void		ft_p_hash_type(t_format *f, int i);
void		ft_printf_p_hash(t_format *f, int j, size_t nbr, int i);
int			ft_putnchar(char c, int n, int fd);
char		*ft_uitoa(unsigned long int num);
int			ft_atoi2(const char *str, t_format *f);
long int	ft_abs(long int n);
int			ft_hex_len(size_t nbr);
void		recursive_hex_pos(size_t nbr, char *base, t_format *f);

#endif
