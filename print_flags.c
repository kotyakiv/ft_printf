#include "ft_printf.h"

void	check_minus_arg(long long arg, t_flags *flag)
{
	if (arg < 0)
	{
		flag->negative = 1;
		flag->space = 0;
	}
	if (arg == 0)
		flag->arg_zero = 1;
}

void	check_minus_f(long double arg, t_flags *flag)
{
	if (arg < 0)
	{
		flag->negative = 1;
		flag->space = 0;
	}
}

void	check_unarg(unsigned long long arg, t_flags *flag)
{
	if (arg == 0)
		flag->arg_zero = 1;
}

void	check_hash_width(t_flags *flag)
{
	if (flag->hash)
	{
		if (flag->specifier == 'o')
			flag->width--;
		if (flag->specifier == 'x' || flag->specifier == 'X' \
			|| flag->specifier == 'p')
			flag->width -= 2;
	}
}

void	print_hash(t_flags *flag)
{
	if (flag->hash)
	{
		if (flag->specifier == 'o')
		{
			ft_putchar('0');
			flag->total++;
		}
		if (flag->specifier == 'x')
		{
			ft_putstr("0x");
			flag->total += 2;
		}
		if (flag->specifier == 'X')
		{
			ft_putstr("0X");
			flag->total += 2;
		}
	}
}

void	print_sign(t_flags *flag)
{
	if (flag->negative)
	{
		ft_putchar('-');
		flag->total++;
	}
	else if (flag->plus)
	{
		ft_putchar('+');
		flag->total++;
	}
}

void	print_sign_or_hash(t_flags *flag, int num_dig)
{
	check_hash_width(flag);
	if (flag->precision != -1 || !flag->zero)
	{
		print_width(flag, num_dig, 1);
		if (flag->specifier == 'd' || flag->specifier == 'i')
			print_sign(flag);
		else if (!flag->arg_zero)
			print_hash(flag);
		else if (flag->specifier == 'o' && !flag->precision && flag->arg_zero)
			print_hash(flag);
	}
	else
	{
		if (flag->specifier == 'd' || flag->specifier == 'i')
			print_sign(flag);
		else if (!flag->arg_zero)
			print_hash(flag);
		else if (flag->specifier == 'o' && !flag->precision && flag->arg_zero)
			print_hash(flag);
		print_width(flag, num_dig, 1);
	}
}

void	print_flag_space(t_flags *flag)
{
	if (flag->space)
	{
		ft_putchar(' ');
		flag->total++;
		if (flag->width)
			flag->width--;
	}
}

void	print_precision(t_flags *flag, int num_dig)
{
	int i;

	i = 0;
	if (flag->specifier == 'o' && flag->hash && flag->precision > 1)
		flag->precision--;
	while (i++ < flag->precision - num_dig)
	{
		ft_putchar('0');
		flag->total++;
		flag->zero_printed = 1;
	}
}

void	width_first_call(t_flags *flag, int num_dig)
{
	if (flag->negative || flag->plus)
		flag->width--;
	if (flag->arg_zero && !flag->zero && flag->precision == -1)
	{
		flag->width--;
		return ;
	}
	if (flag->specifier == 's')
		flag->width -= ft_smaller(flag->precision, num_dig);
	else
		flag->width -= ft_bigger(flag->precision, num_dig);
}

void	print_width(t_flags *flag, int num_dig, int first_call)
{
	int i;

	if (first_call)
		width_first_call(flag, num_dig);
	i = 0;
	if (first_call && !flag->minus)
	{
		while (i++ < flag->width)
		{
			if (flag->zero)
			{
				ft_putchar('0');
				flag->zero_printed = 1;
			}
			else
				ft_putchar(' ');
			flag->total++;
		}
	}
	if (!first_call && flag->minus)
	{
		while (i++ < flag->width)
		{
			ft_putchar(' ');
			flag->total++;
		}
	}
}


