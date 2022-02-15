/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:51:16 by ykot              #+#    #+#             */
/*   Updated: 2022/02/15 16:07:59 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_init(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->modifier = 0;
	flag->print_nothing = 0;
	flag->negative = 0;
	flag->arg_zero = 0;
	flag->zero_printed = 0;
	flag->total = 0;
	flag->specifier = '!';
}

void flags_override(t_flags *flag)
{
	if (flag->space && flag->plus)
		flag->space = 0;
	if (flag->minus && flag->zero)
		flag->zero = 0;
	if (flag->precision != -1 && (flag->specifier == 'd' \
		|| flag->specifier == 'i' || flag->specifier == 'x' \
		|| flag->specifier == 'X' || flag->specifier == 'o' \
		|| flag->specifier == 'f' || flag->specifier == 'u'))
		flag->zero = 0;
	if (flag->specifier == 'c' || flag->specifier == 's' || \
		flag->specifier == 'p')
		flag->zero = 0;
	if (flag->specifier == 'f' && flag->precision == -1)
		flag->precision = 6;
}

void	read_star(int *i, t_flags *flag, va_list *ap, int is_prec)
{
	if (!is_prec)
		flag->width = va_arg(*ap, int);
	else
		flag->precision = va_arg(*ap, int);
	if (!is_prec && flag->width < 0)
	{
		flag->width *= -1;
		flag->minus = 1;
	}
	else if (is_prec && flag->precision < 0)
		flag->precision = -1;
	(*i)++;
}
 
int	conversion_specification(const char *str, int *i, t_flags *flag, va_list *ap)
{
	int pos;
	int j;
	int result;

	pos = str[*i];
	flag_init(flag);
	read_flags(str, i, flag);
	if (str[*i] == '*')
		read_star(i, flag, ap, 0);
	else
		read_precision_width(str, i, flag, 0);
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
			read_star(i, flag, ap, 1);
		else
			read_precision_width(str, i, flag, 1);
	}
	read_modifier(str, i, flag);
	result = read_specifier(str, i, flag);
	if (!result)
	{
		if (str[*i] == '%')
		{
			ft_putchar('%');
			flag->total++;
			return (0);
		}
		if (str[*i] == '\0')
		{
			flag->total = -1;
			return (1);
		}
	}
	else if (result == 2)
	{
		j = 0;
		while (j < *i - pos)
		{
			ft_putchar(str[pos + j]);
			return (2);
		}
	}
	flags_override(flag);
	return (0);
}
