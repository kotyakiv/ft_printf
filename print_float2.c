/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:42:37 by ykot              #+#    #+#             */
/*   Updated: 2022/03/09 16:27:17 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_power(long double base, int exp)
{
	int			i;
	long double	total;

	i = 0;
	total = 0.0;
	if (exp >= 1)
		total = base;
	else
		return (1);
	while (++i < exp)
		total *= base;
	return (total);
}

void	width_first_call_f(t_flags *flag, int num_dig)
{
	flag->width -= num_dig;
	if (flag->negative || flag->plus)
		flag->width--;
	if (flag->arg_zero && !flag->zero && flag->precision == 0)
		flag->width--;
}

void	print_width_f(t_flags *flag, int num_dig, int first_call)
{
	int	i;

	if (first_call)
		width_first_call_f(flag, num_dig);
	i = 0;
	if (first_call && !flag->minus)
	{
		while (i++ < flag->width)
		{
			if (flag->zero)
			{
				ft_putchar('0');
				flag->total++;
			}
			else
				putspace(flag);
		}
	}
	if (!first_call && flag->minus)
	{
		while (i++ < flag->width)
			putspace(flag);
	}
}

void	print_sign_f(t_flags *flag, int num_dig)
{
	if (flag->precision)
		flag->width -= (flag->precision);
	if (flag->precision || !flag->zero)
	{
		print_width_f(flag, num_dig, 1);
		print_sign(flag);
	}
	else
	{
		print_sign(flag);
		print_width_f(flag, num_dig, 1);
	}
}
