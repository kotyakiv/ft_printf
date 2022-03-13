/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:09:43 by ykot              #+#    #+#             */
/*   Updated: 2022/03/13 16:16:53 by ykot             ###   ########.fr       */
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

void	read_arg_f(long double *arg, t_flags *flag, va_list *ap)
{
	if (flag->modifier == 5)
		*arg = va_arg(*ap, long double);
	else
		*arg = (double) va_arg(*ap, double);
}

char	*read_int_part(long double *arg)
{
	char		*str;
	long double	temp;
	int			i;
	int			exp;

	exp = 0;
	temp = *arg;
	while (temp >= 10.00)
	{
		temp /= 10;
		++exp;
	}
	str = ft_strnew(exp + 1);
	i = 0;
	while (exp >= 0)
	{
		temp = *arg / ft_power(10.0, exp);
		str[i] = (int)temp + '0';
		*arg -= ((int)temp * ft_power(10.0, exp));
		++i;
		exp--;
	}
	return (str);
}

char	*read_frac_part(long double arg, t_flags *flag)
{
	char		*str;
	char		*temp;
	int			i;

	i = 0;
	str = ft_strnew(flag->precision + 1);
	if (!str)
		return (NULL);
	while (i < flag->precision + 1)
	{
		arg *= 10;
		str[i] = (int)arg + '0';
		arg -= ((int)arg);
		++i;
	}
	rounding(&str, 0, flag);
	temp = ft_strsub(str, 0, ft_strlen(str) - 1);
	if (!temp)
		return (NULL);
	ft_strdel(&str);
	str = temp;
	return (str);
}
