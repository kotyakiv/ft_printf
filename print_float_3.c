#include "ft_printf.h"
#include <stdio.h>

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

void	round_int(char **str, int is_int_part, t_flags *flag, int modflag)
{
	char *temp;

	if ((*str)[0] == '0' && modflag && is_int_part)
	{
		temp = ft_strjoin("1", *str);
		free(*str);
		*str = temp;
	}
	else if (is_int_part && flag->int_round)
		(*str)[ft_strlen(*str) - 1]++;
	if (modflag && !is_int_part)
		flag->int_round = 1;
}

void	rounding(char **str, int is_int_part, t_flags *flag)
{
	int	i;
	int	modflag;

	modflag = 1;
	i = ft_strlen(*str) - 1;
	if (!is_int_part)
		(*str)[i] += 4;
	while (modflag && i >= 0)
	{
		modflag = 0;
		(*str)[i]++;
		if ((*str)[i] > '9')
		{
			(*str)[i] = '0';
			modflag = 1;
			--i;
		}
		else if (flag->int_round && is_int_part)
			(*str)[i]--;
	}
	round_int(str, is_int_part, flag, modflag);
}

char *read_frac_part(long double arg, t_flags *flag)
{
	char 		*str;
	char		*temp;
	int			i;

	i = 0;
	str = ft_strnew(flag->precision + 1);
	if (!str)
		return (NULL);
	while (i < flag->precision + 1)
	{
		arg *= 10;
		str[i] = (int)arg + '0';
		arg -= ((int)arg);
		++i;
	}
	rounding(&str, 0, flag);
	temp = ft_strsub(str, 0, ft_strlen(str) - 1);
	if (!temp)
		return (NULL);
	ft_strdel(&str);
	str = temp;
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
	if (flag->zero)
	{
		print_sign(flag);
		print_width_f(flag, num_dig, 1);
	}
	else
	{
		print_width_f(flag, num_dig, 1);
		print_sign(flag);
	}
}

int count_dig(char	*part_int, t_flags *flag)
{
	if (flag->precision)
		return (ft_strlen(part_int) + flag->precision + 1);
	else
		return (ft_strlen(part_int));
}

void	bank_round(long double arg, char *part_int, t_flags *flag)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(part_int);
	arg *= 10;
	if  ((int)arg != 5)
		return ;
	arg -= ((int)arg);
	while (i < 18 - len)
	{
		arg *= 10;
		if  ((int)arg != 0)
		{
			flag->int_round = 1;
			return ;
		}
		arg -= ((int)arg);
		++i;
	}
	if (part_int[len - 1] % 2)
		flag->int_round = 1;
}

void	print_float(t_flags *flag, va_list *ap)
{
	long double		arg;
	char			*part_int;
	char			*part_frac;
	int				num_dig;

	read_arg_f(&arg, flag, ap);
	check_minus_arg_f(&arg, flag);
	if (arg == 1.0 / 0.0)
	{
		ft_putstr("inf");
		flag->total += 3;
		return ;
	}
	if (arg == -1.0 / 0.0)
	{
		ft_putstr("-inf");
		flag->total += 4;
		return ;
	}
	part_int = read_int_part(&arg);
	if (flag->precision == 0)
		bank_round(arg, part_int, flag);
	else
	{
		part_frac = read_frac_part(arg, flag);
		if (!part_frac)
		{
			flag->total = -1;
			return ;
		}
	}
	if (flag->int_round)
		rounding(&part_int, 1, flag);
	num_dig = count_dig(part_int, flag);
	print_flag_space(flag);
	print_sign_f(flag, num_dig);
	ft_putstr(part_int);
	if (flag->precision)
	{
		ft_putchar('.');
		ft_putstr(part_frac);
	}
	print_width_f(flag, num_dig, 0);
	flag->total += num_dig;
	ft_strdel(&part_int);
	if (flag->precision)
		ft_strdel(&part_frac);
}
