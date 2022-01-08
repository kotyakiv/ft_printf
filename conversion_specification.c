#include "ft_printf.h"

void flag_init(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->apostrophe = 0;
	flag->length = 0;
	flag->width = 0;
	flag->modifier = 0;
	flag->specifier = '!';
}

void	check_flags(const char *str, int *i, t_flags *flag)
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
		if (str[*i] == '\'')
			flag->apostrophe = 1;
		(*i)++;
	}
}

void	check_width_length(const char *str, int *i, t_flags *flag, int is_len)
{
	char	*char_number;
	int		j;

	char_number = ft_strnew(10);
	while (str[*i] == '0')
		(*i)++;
	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		char_number[j++] = str[*i];
		if (j >= 10 && strcmp(char_number, "2147483647") > 0)
			return ; //finish later
		(*i)++;
	}
	if (is_len)
		flag->length = ft_atoi(char_number);
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

void	conversion_specification(const char *str, int *i, t_flags *flag)
{
	flag_init(flag);
	check_flags(str, i, flag);
	check_width_length(str, i, flag, 0);
	if (str[*i] == '.')
	{
		(*i)++;
		check_width_length(str, i, flag, 1);
	}
	check_modifier(str, i, flag);
	check_specifier(str, i, flag);
}