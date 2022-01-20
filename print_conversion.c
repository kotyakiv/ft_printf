#include "ft_printf.h"

void	print_char(t_flags *flag, va_list *ap)
{
	int arg;
	int i;

	arg = va_arg(*ap, int);
	if (flag->width > 1)
	{
		i = 1;
		while (i++ < flag->width)
			ft_putchar(' ');
	}
    ft_putchar(arg);
}

void	print_pointer(va_list *ap)
{
	long long arg;

	arg = va_arg(*ap, unsigned long long);
	if (!arg)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_putstr("0x");
	ft_putstr(dem_to_base(arg, 16));
}


void	print_str(t_flags *flag, va_list *ap)
{
	char 	*arg;
	int		i;

	arg = va_arg(*ap, char *);
	if (!arg)
	{
		i = 0;
		while (i++ < flag->width - ft_smaller(flag->precision, ft_strlen(arg)))
			ft_putchar(' ');
		ft_putstr("(null)");
		return ;
	}
	i = 0;
	while (i++ < flag->width - ft_smaller(flag->precision, ft_strlen(arg)))
		ft_putchar(' ');
	i = 0;
	while (i < ft_smaller(flag->precision, ft_strlen(arg)) && arg[i])
		ft_putchar(arg[i++]);
	print_a_width(flag);
}

void	print_conversion(t_flags *flag, va_list *ap)
{
	if (flag->print_nothing)
		return ;
	if (flag->specifier == 'c')
		print_char(flag, ap);
	if (flag->specifier == 's')
		print_str(flag, ap);
	if (flag->specifier == 'p')
		print_pointer(ap);
	if (flag->specifier == 'd')
		print_decimal(flag, ap);
	if (flag->specifier == 'o')
		print_octal(flag, ap);
	if (flag->specifier == 'x' || flag->specifier == 'X')
		print_hexadecimal(flag, ap);
	if (flag->specifier == 'u')
		print_unsigned(flag, ap);
	if (flag->specifier == 'f')
		print_float(flag, ap);
}