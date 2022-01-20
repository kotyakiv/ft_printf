#include "ft_printf.h"

long long ft_power(int base, int exp)
{
	int i;
	long long	total;

	i = 0;
	total = 0;
	if (exp >= 1)
		total = base;
	while (++i < exp)
		total *= base;
	return (total); 
}

void	float_flags_override(t_flags *flag)
{
	if (flag->precision == 0)
		flag->precision = 6;
}

void	print_sign_f(t_flags *flag, long double arg)
{
	if (arg < 0)
		ft_putchar('-');
	else if (flag->plus)
		ft_putchar('+');
}

void	check_minus_f(long double arg, t_flags *flag)
{
	if (arg < 0)
		flag->width--;
	else if (flag->plus)
		flag->width--;
}

void	read_floatarg(long double *arg, t_flags *flag, va_list *ap)
{
	if (flag->modifier == 4)
		*arg = (double) va_arg(*ap, double);
	else if (flag->modifier == 5)
		*arg = va_arg(*ap, long double);
	else
		*arg = (float) va_arg(*ap, double);
}

void	print_float(t_flags *flag, va_list *ap)
{
	long long			int_value;
	long double			arg;
	int					num_dig;

	float_flags_override(flag);
	read_floatarg(&arg, flag, ap);
	num_dig = num_digit((long long)arg, 10);
	check_minus_f(arg, flag);
	print_flag_space(flag);
	print_sign_f(flag, arg);
	print_b_width(flag, num_dig);
	int_value = (long long) arg;
	ft_putllnbr(ft_abs(int_value));
	if (flag->precision)
	{
		ft_putchar('.');
		arg -= int_value;
		//printf("\n%Lf\n", arg);
		arg *= ft_power(10, flag->precision);
		int_value = (long long) arg;
		num_dig = num_digit((long long)int_value, 10);
		if (int_value != 0)
			ft_putllnbr(ft_abs(int_value));
		print_precision(flag, num_dig);
		flag->width -= (num_dig + 1); 
	}
	print_a_width(flag);
}
