/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:15:34 by ykot              #+#    #+#             */
/*   Updated: 2022/02/16 16:23:50 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_flags *flag)
{
	print_width(flag, 1, 1);
	ft_putchar('%');
	flag->total++;
	print_width(flag, 1, 0);
}

void	print_char(t_flags *flag, va_list *ap)
{
	int	arg;

	arg = va_arg(*ap, int);
	print_width(flag, 1, 1);
	ft_putchar(arg);
	flag->total++;
	print_width(flag, 1, 0);
}

void	print_pointer(t_flags *flag, va_list *ap)
{
	unsigned long	arg;
	int				num_dig;
	char			*str;

	arg = va_arg(*ap, unsigned long);
	num_dig = num_undigit(arg, 16);
	if (!arg && flag->precision)
		num_dig = 1;
	flag->width -= 2;
	flag->total += num_dig + 2;
	print_width(flag, num_dig, 1);
	ft_putstr("0x");
	print_precision(flag, num_dig);
	if (!arg && flag->precision)
		ft_putchar('0');
	else
	{
		str = dem_to_base(arg, 16);
		ft_putstr(str);
		ft_strdel(&str);
	}
	print_width(flag, num_dig, 0);
}

void	print_str_null(t_flags *flag)
{
	flag->width -= 6;
	print_width(flag, 0, 1);
	ft_putstr("(null)");
	flag->total += 6;
	print_width(flag, 0, 0);
}

void	print_str(t_flags *flag, va_list *ap)
{
	char	*arg;
	int		len;
	int		i;

	arg = va_arg(*ap, char *);
	if (!arg)
	{
		if (flag->precision >= 6 || flag->precision == -1)
		{
			print_str_null(flag);
			return ;
		}
		print_width(flag, 0, 1);
		print_width(flag, 0, 0);
		return ;
	}
	len = ft_smaller(flag->precision, ft_strlen(arg));
	print_width(flag, len, 1);
	i = 0;
	while (i < len)
	{
		ft_putchar(arg[i++]);
		flag->total++;
	}
	print_width(flag, len, 0);
}
