#include "ft_printf.h"

void	print_sign(t_flags *flag, long long arg)
{
	if (arg < 0)
		ft_putchar('-');
	else if (flag->plus)
		ft_putchar('+');
}

void	print_flag_space(t_flags *flag)
{
	if (flag->space)
	{
		ft_putchar(' ');
		if (flag->width)
			flag->width--;
	}

}
 
void	print_b_width(t_flags *flag, int num_dig)
{
	int i;

	i = 0;
	if (flag->specifier == 'f')
	{
		while (i++ < flag->width - num_dig && !flag->minus)
		{
			if (flag->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else
	{
		while (i++ < flag->width - ft_bigger(num_dig, flag->precision) && !flag->minus)
		{
			if (flag->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	if (flag->minus && flag->specifier != 'f')
		flag->width -= ft_bigger(num_dig, flag->precision);
	else if (flag->minus && flag->specifier == 'f')
		flag->width -= num_dig;
}

void	print_a_width(t_flags *flag)
{
	int i;

	i = 0;
	while (i++ < flag->width && flag->minus)
		ft_putchar(' ');

}

void	print_precision(t_flags *flag, int num_dig)
{
	int i;

	i = 0;
	while (i++ < flag->precision - num_dig)
		ft_putchar('0');
}

void	check_minus(long long arg, t_flags *flag)
{
	if (arg < 0)
	{
		flag->width--;
		flag->space = 0;
	}
	else if (flag->plus)
		flag->width--;
}