#include "ft_printf.h"

void flag_init(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->modifier = 0;
	flag->print_nothing = 0;
	flag->negative = 0;
	flag->arg_zero = 0;
	flag->zero_printed = 0;
	flag->total = 0;
	flag->specifier = '!';
}

void	read_flags(const char *str, int *i, t_flags *flag)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == '#' \
	|| str[*i] == '0' || str[*i] == ' ' || str[*i] == '\'')
	{
		if (str[*i] == '-')
			flag->minus = 1;
		if (str[*i] == '+')
			flag->plus = 1;
		if (str[*i] == '#')
			flag->hash = 1;
		if (str[*i] == '0')
			flag->zero = 1;
		if (str[*i] == ' ')
			flag->space = 1;
		(*i)++;
	}
}

void	read_precision_width(const char *str, int *i, t_flags *flag, int is_prec)
{
	char	*char_number;
	int		j;

	char_number = ft_strnew(11);
	while (str[*i] == '0')
	{
		if (is_prec)
			flag->precision = 0;
		(*i)++;
	}
	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		char_number[j++] = str[*i];
		if (j >= 10 && strcmp(char_number, "2147483647") > 0)
			flag->print_nothing = 1;
		(*i)++;
	}
	if (is_prec)
		flag->precision = ft_atoi(char_number);
	else
		flag->width = ft_atoi(char_number);
	ft_strdel(&char_number);
}

void	read_modifier(const char *str, int *i, t_flags *flag)
{
	if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			flag->modifier = 1;
			(*i)++;
		}
		else
			flag->modifier = 2;
		(*i)++;
	}
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
		{
			flag->modifier = 4;
			(*i)++;
		}
		else
			flag->modifier = 3;
		(*i)++;
	}
	if (str[*i] == 'L')
	{
		flag->modifier = 5;
		(*i)++;
	}
}

int		read_specifier(const char *str, int *i, t_flags *flag)
{
	if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'x' || \
		str[*i] == 'X' || str[*i] == 'o' || str[*i] == 'c' || \
		str[*i] == 'p' || str[*i] == 'f' || str[*i] == 's' || \
		str[*i] == 'u' || str[*i] == 'b' || str[*i] == 'n' || \
		str[*i] == 'e' || str[*i] == 'E' || str[*i] == 'g')
	{
		flag->specifier = str[*i];
		return (1);
	}
	else if (ft_isalpha(str[*i]))
		return (2);
	return (0);
}

void flags_override(t_flags *flag)
{
	if (flag->space && flag->plus)
		flag->space = 0;
	if (flag->minus && flag->zero)
		flag->zero = 0;
	if (flag->precision != -1 && (flag->specifier == 'd' \
		|| flag->specifier == 'i' || flag->specifier == 'x' \
		|| flag->specifier == 'X' || flag->specifier == 'o' \
		|| flag->specifier == 'f' || flag->specifier == 'u'))
		flag->zero = 0;
	if (flag->specifier == 'c' || flag->specifier == 's' || \
		flag->specifier == 'p')
		flag->zero = 0;
	if (flag->specifier == 'f' && flag->precision == -1)
		flag->precision = 6;
}

void	read_star(int *i, t_flags *flag, va_list *ap, int is_prec)
{
	if (!is_prec)
		flag->width = va_arg(*ap, int);
	else
		flag->precision = va_arg(*ap, int);
	if (!is_prec && flag->width < 0)
	{
		flag->width *= -1;
		flag->minus = 1;
	}
	else if (is_prec && flag->precision < 0)
		flag->precision = -1;
	(*i)++;
}
 
int	conversion_specification(const char *str, int *i, t_flags *flag, va_list *ap)
{
	int pos;
	int j;
	int result;

	pos = str[*i];
	flag_init(flag);
	read_flags(str, i, flag);
	if (str[*i] == '*')
		read_star(i, flag, ap, 0);
	else
		read_precision_width(str, i, flag, 0);
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
			read_star(i, flag, ap, 1);
		else
			read_precision_width(str, i, flag, 1);
	}
	read_modifier(str, i, flag);
	result = read_specifier(str, i, flag);
	if (!result)
	{
		if (str[*i] == '%')
		{
			ft_putchar('%');
			flag->total++;
			return (0);
		}
		if (str[*i] == '\0')
		{
			flag->total = -1;
			return (1);
		}
	}
	else if (result == 2)
	{
		j = 0;
		while (j < *i - pos)
		{
			ft_putchar(str[pos + j]);
			return (2);
		}
	}
	flags_override(flag);
	return (0);
}
