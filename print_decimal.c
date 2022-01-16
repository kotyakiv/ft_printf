#include "ft_printf.h"

void	ft_putllnbr(long long n)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putllnbr(n / 10);
	c = n % 10 + '0';
	ft_putchar(c);
}

long long ft_bigger(long long a, long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long long ft_abs(long long a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

void	print_sign(t_flags *flag, long long llarg)
{
	if (llarg < 0)
		ft_putchar('-');
	else if (flag->plus)
		ft_putchar('+');
}

void	check_print_space(t_flags *flag)
{
	if (flag->space)
	{
		ft_putchar(' ');
		if (flag->width)
			flag->width--;
	}
}

void	print_space_or_zero(t_flags *flag, int num_dig)
{
	int i;

	i = 0;
	while (i++ < flag->width - ft_bigger(num_dig, flag->precision) && !flag->minus)
	{
		if (flag->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void	print_precision(t_flags *flag, int num_dig)
{
	int i;

	i = 0;
	while (i++ < flag->precision - num_dig)
		ft_putchar('0');
}

void	check_minus(long long llarg, t_flags *flag)
{
	if (llarg < 0)
		flag->width--;
	else if (flag->plus)
		flag->width--;
}

void	decimal_flags_override(t_flags *flag)
{
	if (flag->precision != 0)
		flag->zero = 0;
	if (flag->space && flag->plus)
		flag->space = 0;
}

void	print_decimal(t_flags *flag, va_list *ap)
{
	long long	arg;
	int			num_dig;

	decimal_flags_override(flag);
	if (flag->modifier == 1)
		arg = (char) va_arg(*ap, int);
	else if (flag->modifier == 2)
		arg = (short) va_arg(*ap, int);
	else if (flag->modifier == 3)
		arg = (long) va_arg(*ap, long long);
	else if (flag->modifier == 4)
		arg = va_arg(*ap, long long);
	else
		arg = (int) va_arg(*ap, int);
	num_dig = num_digit(arg, 10);
	check_print_space(flag);
	check_minus(arg, flag);
	print_space_or_zero(flag, num_dig);
	print_sign(flag, arg);
	print_precision(flag, num_dig);
	ft_putllnbr(ft_abs(arg));
}