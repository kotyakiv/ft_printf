/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:50:55 by ykot              #+#    #+#             */
/*   Updated: 2022/03/09 12:44:29 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	specifier;
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		modifier;
	int		negative;
	int		arg_zero;
	int		zero_printed;
	int		total;
}				t_flags;

/*
**	ft_printf
*/

int			ft_printf(const char *str, ...);

/*
**	conversion_specification
*/

void		conv_spec(const char *str, int *i, t_flags *flag, va_list *ap);

/*
**	checking
*/

void		check_unarg(unsigned long long arg, t_flags *flag);
void		check_minus_arg(long long arg, t_flags *flag);
void		check_minus_arg_f(long double *arg, t_flags *flag);
void		check_hash_width(t_flags *flag);

/*
** reading_option
*/

void		read_flags(const char *str, int *i, t_flags *flag);
void		read_precision_width(const char *str, int *i, \
			t_flags *flag, int is_prec);
void		read_modifier(const char *str, int *i, t_flags *flag);
void		read_star(int *i, t_flags *flag, va_list *ap, int is_prec);

/*
**	to_base
*/

void		ft_strrev(char *str);
int			num_undigit(unsigned long long num, int base);
int			num_digit(long long num, int base);
char		ft_digit(unsigned long long num, int base);
char		*dem_to_base(unsigned long long num, int base);

/*
**	print_flags
*/

void		print_sign(t_flags *flag);
void		print_flag_space(t_flags *flag);
void		print_hash(t_flags *flag);
void		print_sign_or_hash(t_flags *flag, int num_dig);

/*
**	width_precision
*/

void		width_first_call(t_flags *flag, int num_dig);
void		print_precision(t_flags *flag, int num_dig);
void		print_width(t_flags *flag, int num_dig, int first_call);
void		putspace(t_flags *flag);

/*
**	sub-functions
*/

void		ft_putllnbr(long long n);
void		ft_putllunbr(unsigned long long n);
long long	ft_bigger(long long a, long long b);
long long	ft_smaller(long long a, long long b);
void		str_toupper(char *str);

/*
**	print_scp
*/

void		print_percent(t_flags *flag);
void		print_char(t_flags *flag, va_list *ap);
void		print_pointer(t_flags *flag, va_list *ap);
void		print_str(t_flags *flag, va_list *ap);

/*
**	print_decimal
*/

void		print_decimal(t_flags *flag, va_list *ap);

/*
**	print_unsigned
*/

void		read_unsignedarg(unsigned long long *arg, \
			t_flags *flag, va_list *ap);
void		print_unsigned(t_flags *flag, va_list *ap);
void		print_octal(t_flags *flag, va_list *ap);
void		print_hexadecimal(t_flags *flag, va_list *ap);
void		print_binary(t_flags *flag, va_list	*ap);

/*
**	print_conversion
*/

void		print_conversion(t_flags *flag, va_list *ap);
void		type_conv(int select, t_flags *flag, va_list *ap);
/*
**	print_float
*/

void		print_float(t_flags *flag, va_list *ap);

/*
**	print_float2
*/

long double	ft_power(long double base, int exp);
void		width_first_call_f(t_flags *flag, int num_dig);
void		print_width_f(t_flags *flag, int num_dig, int first_call);
void		print_sign_f(t_flags *flag, int num_dig);

/*
**	function dispatcher
*/

typedef void	t_conversion(t_flags *flag, va_list *ap);

#endif