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
	str = ft_strnew(17);
	while (i < 16)
	{
		arg *= 10;
		str[i] = (int)arg + '0'; 
		arg -= ((int)arg);
		++i;
	}
	return (str);
}

void	width_first_call_f(t_flags *flag, int num_dig)
{
	flag->width -= num_dig;
	if (flag->negative || flag->plus)
		flag->width--;
	if (flag->arg_zero && !flag->zero && flag->precision == 0)
		flag->width--;
}

void print_width_f(t_flags *flag, int num_dig, int first_call)
{
	int	i;

	if (first_call)
		width_first_call_f(flag, num_dig);
	i = 0;
	if (first_call && !flag->minus)
	{
		while (i++ < flag->width)
		{
			if (flag->zero)
			{
				ft_putchar('0');
				flag->total++;
			}
			else
				putspace(flag);
		}
	}
	if (!first_call && flag->minus)
	{
		while (i++ < flag->width)
			putspace(flag);
	}
}

void	print_sign_f(t_flags *flag, int num_dig)
{
	if (flag->precision || !flag->zero)
	{
		print_width_f(flag, num_dig, 1);
		print_sign(flag);
	}
	else
	{
		print_sign(flag);
		print_width_f(flag, num_dig, 1);
	}
}

void	rounding_print(t_flags flag, char *frac)
{
	int i;

	i = 0;
	while (i <= flag.precision)
	{
		ft_putchar(frac[i]);
		++i;
	}
}

void	print_frac(t_flags *flag, char *frac)
{
	int len;
	int cont;

	len = 15;
	cont = 1;
	while (len && cont)
	{
		cont = 0;
		if (frac[len] == '9')
		{
			cont = 1;
			frac[len]= '0';
			len--;
		}
	}
	frac[len] += 1;
	rounding_print(*flag, frac);
}

void	print_float(t_flags *flag, va_list *ap)
{
	long double		arg;
	char			*part_int;
	char			*part_frac;
	int				num_dig;

	read_arg_f(&arg, flag, ap);
	check_minus_arg_f(&arg, flag);
	part_int = read_int_part(&arg);
	part_frac = read_frac_part(arg);
	if (flag->precision)
		num_dig = ft_strlen(part_int) + flag->precision + 1;
	else
		num_dig = ft_strlen(part_int);
	print_flag_space(flag);
	print_sign_f(flag, num_dig);
	ft_putstr(part_int);
	if (flag->precision)
	{
		ft_putchar('.');
		print_frac(flag, part_frac);
	}
	print_width_f(flag, num_dig, 0);
	flag->total += num_dig;
	ft_strdel(&part_int);
	ft_strdel(&part_frac);
}