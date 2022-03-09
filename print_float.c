/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:43:05 by ykot              #+#    #+#             */
/*   Updated: 2022/03/09 16:32:05 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_arg_f(long double *arg, t_flags *flag, va_list *ap)
{
	if (flag->modifier == 5)
		*arg = va_arg(*ap, long double);
	else
		*arg = (double) va_arg(*ap, double);
}

static long long	ft_round(long double x, t_flags *flag)
{
	if (x < 0.0)
		return ((long long) \
		((x - (5 * ft_power(0.1, flag->precision + 1))) * \
			ft_power(10, flag->precision)));
	else
		return ((long long) \
		((x + (5 * ft_power(0.1, flag->precision + 1))) * \
			ft_power(10, flag->precision)));
}

static void	print_precision_f(int *num_dig, long double arg, t_flags *flag)
{
	long long		part_frac;
	int				n;

	ft_putchar('.');
	part_frac = ft_round(arg, flag);
	n = flag->precision - num_digit(part_frac, 10);
	while (n)
	{
		ft_putchar('0');
		flag->total++;
		--n;
	}
	ft_putllnbr(part_frac);
	*num_dig += num_digit(part_frac, 10) + 1;
}

void	print_float(t_flags *flag, va_list *ap)
{
	long double		arg;
	long long		part_int;
	int				num_dig;

	read_arg_f(&arg, flag, ap);
	if (arg == 1.0 / 0.0)
	{
		ft_putstr("inf");
		flag->total += 3;
		return ;
	}
	check_minus_arg_f(&arg, flag);
	part_int = (long long) arg;
	num_dig = num_digit(part_int, 10);
	arg -= part_int;
	print_flag_space(flag);
	print_sign_f(flag, num_dig);
	ft_putllnbr(part_int);
	if (flag->precision)
		print_precision_f(&num_dig, arg, flag);
	print_width_f(flag, num_dig, 0);
	flag->total += num_dig;
}
