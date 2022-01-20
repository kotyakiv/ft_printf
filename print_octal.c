#include "ft_printf.h"

void	read_unarg(unsigned long long *arg, t_flags *flag, va_list *ap)
{
	if (flag->modifier == 1)
		*arg = (unsigned char) va_arg(*ap, unsigned int);
	else if (flag->modifier == 2)
		*arg = (unsigned short) va_arg(*ap, unsigned int);
	else if (flag->modifier == 3)
		*arg = (unsigned long) va_arg(*ap, unsigned long long);
	else if (flag->modifier == 4)
		*arg = va_arg(*ap, unsigned long long);
	else
		*arg = (unsigned int) va_arg(*ap, unsigned int);
}

void	print_octal(t_flags *flag, va_list *ap)
{
	unsigned long long	arg;
	int					num_dig;

	read_unarg(&arg, flag, ap);
	num_dig = num_digit(arg, 8);
	if (arg != 0 && flag->hash)
		flag->width--;
	print_b_width(flag, num_dig);
	if (arg != 0 && flag->hash)
		ft_putchar('0');
	print_precision(flag, num_dig);
	ft_putstr(dem_to_base(arg, 8));
	print_a_width(flag);
}

void	print_hexadecimal(t_flags *flag, va_list *ap)
{
	unsigned long long	arg;
	int					num_dig;
	char				*str;

	read_unarg(&arg, flag, ap);
	num_dig = num_digit(arg, 16);
	if (flag->hash)
		flag->width -= 2;
	print_b_width(flag, num_dig);
	if (arg != 0 && flag->hash)
	{
		if (flag->specifier == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	print_precision(flag, num_dig);
	str = dem_to_base(arg, 16);
	if (flag->specifier == 'X')
		str_toupper(str);
	ft_putstr(str);
	print_a_width(flag);
}

void	print_unsigned(t_flags *flag, va_list *ap)
{
	unsigned long long	arg;
	int					num_dig;

	read_unarg(&arg, flag, ap);
	num_dig = num_digit(arg, 10);
	print_b_width(flag, num_dig);
	print_precision(flag, num_dig);
	if (arg != 0)
		ft_putllunbr(arg);
	print_a_width(flag);
}
