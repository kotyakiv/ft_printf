#include "ft_printf.h"

long double ft_power(long double base, int exp)
{
	int i;
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

char *read_int_part(long double *arg)
{
	char 		*str;
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

char *read_frac_part(long double arg)
{
	char 		*str;
	int			i;

	i = 0;
	str = ft_strnew(20);
	while (i < 20)
	{
		arg *= 10;
		str[i] = (int)arg + '0'; 
		arg -= ((int)arg);
		++i;
	}

	return (str);
}

void printf_width_f()
{
	
}


void	print_float(t_flags *flag, va_list *ap)
{
	long double		arg;
	char			*part_int;
	char			*part_frac;

	read_arg_f(&arg, flag, ap);
	part_int = read_int_part(&arg);
	part_frac = read_frac_part(arg);
	ft_putstr(part_int);
	ft_putchar('.');
	ft_putstr(part_frac);
	ft_strdel(&part_int);
	ft_strdel(&part_frac);
}