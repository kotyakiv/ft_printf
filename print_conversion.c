/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:02:32 by ykot              #+#    #+#             */
/*   Updated: 2022/02/16 17:08:25 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion(t_flags *flag, va_list *ap)
{
	if (flag->specifier == '%')
		print_percent(flag);
	if (flag->specifier == 'c')
		print_char(flag, ap);
	if (flag->specifier == 's')
		print_str(flag, ap);
	if (flag->specifier == 'p')
		print_pointer(flag, ap);
	if (flag->specifier == 'd' || flag->specifier == 'i')
		print_decimal(flag, ap);
	if (flag->specifier == 'o')
		print_octal(flag, ap);
	if (flag->specifier == 'x' || flag->specifier == 'X')
		print_hexadecimal(flag, ap);
	if (flag->specifier == 'u')
		print_unsigned(flag, ap);
	if (flag->specifier == 'f')
		print_float(flag, ap);
	if (flag->specifier == 'b')
		print_binary(flag, ap);
}
