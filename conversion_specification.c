#include "ft_printf.h"

void flag_init(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->star = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->modifier = 0;
	flag->print_nothing = 0;
	flag->specifier = '!';
}

void	check_flags(const char *str, int *i, t_flags *flag)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == '#' \
	|| str[*i] == '0' || str[*i] == ' ')
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
		if (str[*i] == '*')
			flag->star = 1;
		(*i)++;
	}
}

void	check_precision_width(const char *str, int *i, t_flags *flag, int is_prec)
{
	char	*char_number;
	int		j;

	char_number = ft_strnew(10);
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
}

void	check_modifier(const char *str, int *i, t_flags *flag)
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

void	check_specifier(const char *str, int *i, t_flags *flag)
{
	if (str[*i] == 'd' || str[*i] == 'i')
		flag->specifier = 'd';
	if (str[*i] == 'x')
		flag->specifier = 'x';
	if (str[*i] == 'X')
		flag->specifier = 'X';
	if (str[*i] == 'o')
		flag->specifier = 'o';
	if (str[*i] == 'c')
		flag->specifier = 'c';
	if (str[*i] == 'p')
		flag->specifier = 'p';
	if (str[*i] == 'f')
		flag->specifier = 'f';
	if (str[*i] == 's')
		flag->specifier = 's';
	if (str[*i] == 'u')
		flag->specifier = 'u';
	if (str[*i] == 'e')
		flag->specifier = 'e';
}

void if_flags_override(t_flags *flag)
{

	if (flag->space && flag->plus)
		flag->space = 0;
	if (flag->minus && flag->zero)
		flag->zero = 0;
	if (flag->precision && (flag->specifier == 'd' || flag->specifier == 'x' \
		|| flag->specifier == 'X' || flag->specifier == 'o' \
		|| flag->specifier == 'f' || flag->specifier == 'u'))
		flag->zero = 0;
	if (flag->specifier != 'f' && flag->specifier != 's' && flag->precision == -1 )
		flag->precision = 0;
	if (flag->specifier == 'f' && flag->precision == -1)
		flag->precision = 6;
	// was in demical
	if (flag->precision != 0)
		flag->zero = 0;
}

void	conversion_specification(const char *str, int *i, t_flags *flag)
{
	flag_init(flag);
	check_flags(str, i, flag);
	check_precision_width(str, i, flag, 0);
	if (str[*i] == '.')
	{
		(*i)++;
		check_precision_width(str, i, flag, 1);
	}
	check_modifier(str, i, flag);
	check_specifier(str, i, flag);
	if_flags_override(flag);
}