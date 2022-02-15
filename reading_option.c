/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:06:54 by ykot              #+#    #+#             */
/*   Updated: 2022/02/15 16:17:40 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	read_precision_width(const char *str, int *i, t_flags *flag, int is_pr)
{
	char	*char_number;
	int		j;

	char_number = ft_strnew(11);
	while (str[*i] == '0')
	{
		if (is_pr)
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
	if (is_pr)
		flag->precision = ft_atoi(char_number);
	else
		flag->width = ft_atoi(char_number);
	ft_strdel(&char_number);
}

static void	read_dl_mod(const char *str, int *i, t_flags *flag)
{
	if (str[*i] == 'L')
	{
		flag->modifier = 5;
		(*i)++;
	}
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
	read_dl_mod(str, i, flag);
}

int	read_specifier(const char *str, int *i, t_flags *flag)
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
