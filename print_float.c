/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:30:30 by ykot              #+#    #+#             */
/*   Updated: 2022/03/13 17:23:01 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_dig(char	*part_int, t_flags *flag)
{
	if (flag->precision)
		return (ft_strlen(part_int) + flag->precision + 1);
	else
		return (ft_strlen(part_int));
}

static int	if_not_nan_inf(long double arg, t_flags *flag, char **part_int)
{
	if (arg == 1.0 / 0.0)
	{
		*part_int = ft_strdup("inf");
		flag->precision = 0;
		flag->zero = 0;
		return (0);
	}
	if (arg == -1.0 / 0.0)
	{
		*part_int = ft_strdup("-inf");
		flag->precision = 0;
		flag->zero = 0;
		return (0);
	}
	if (arg != arg)
	{
		*part_int = ft_strdup("nan");
		flag->zero = 0;
		flag->precision = 0;
		return (0);
	}
	return (1);
}

static void	read_int_fr(long double arg, t_flags *flag, \
						char **p_int, char **p_fr)
{
	check_minus_arg_f(&arg, flag);
	*p_int = read_int_part(&arg);
	if (flag->precision == 0)
	{
		if (bank_round(arg, *p_int, flag))
			*p_fr = read_frac_part(arg, flag);
	}
	else
		*p_fr = read_frac_part(arg, flag);
	if (flag->int_round)
		rounding(p_int, 1, flag);
}

void	print_float(t_flags *flag, va_list *ap)
{
	long double		arg;
	char			*part_int;
	char			*part_frac;
	int				num_dig;

	read_arg_f(&arg, flag, ap);
	if (if_not_nan_inf(arg, flag, &part_int))
		read_int_fr(arg, flag, &part_int, &part_frac);
	num_dig = count_dig(part_int, flag);
	print_flag_space(flag);
	print_sign_f(flag, num_dig);
	ft_putstr(part_int);
	if (flag->precision)
	{
		ft_putchar('.');
		ft_putstr(part_frac);
	}
	print_width_f(flag, num_dig, 0);
	g_total += num_dig;
	ft_strdel(&part_int);
	if (flag->precision)
		ft_strdel(&part_frac);
}
