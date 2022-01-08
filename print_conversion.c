#include "ft_printf.h"

void	print_char(va_list *ap)
{
	int arg;

	arg = va_arg(*ap, int);
    ft_putchar(arg);
}

void	print_str(va_list *ap)
{
	char *arg;

	arg = va_arg(*ap, char *);
	ft_putstr(arg);
}

void	print_pointer(va_list *ap)
{
	long long arg;

	arg = va_arg(*ap, long long);
	ft_putstr("0x");
	ft_putstr(dem_to_base(arg, 16));
}

void	print_decimal(va_list *ap)
{
	int	arg;

	arg = va_arg(*ap, int);
	ft_putnbr(arg);
}

void	print_octal(va_list *ap)
{
	long long arg;

	arg = va_arg(*ap, long long);
	ft_putstr(dem_to_base(arg, 8));
}

void str_toupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = ft_toupper(str[i]);
		++i;
	}
}

void	print_hexadecimal(t_flags flag, va_list *ap)
{
	long long 	arg;
	char		*str;

	arg = va_arg(*ap, long long);
	if (flag.specifier == 'x')
		ft_putstr(dem_to_base(arg, 16));
	else
	{
		str = ft_strdup(dem_to_base(arg, 16));
		str_toupper(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

void	print_conversion(t_flags flag, va_list *ap)
{
	if (flag.specifier == 'c')
		print_char(ap);
	if (flag.specifier == 's')
		print_str(ap);
	if (flag.specifier == 'p')
		print_pointer(ap);
	if (flag.specifier == 'd')
		print_decimal(ap);
	if (flag.specifier == 'o')
		print_octal(ap);
	if (flag.specifier == 'x' || flag.specifier == 'X')
		print_hexadecimal(flag, ap);
}