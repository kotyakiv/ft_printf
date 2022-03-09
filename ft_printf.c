/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:51:09 by ykot              #+#    #+#             */
/*   Updated: 2022/03/08 15:05:17 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_one_char(const char *str, int *total, int i)
{
	ft_putchar(str[i]);
	(*total)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flag;
	int		i;
	int		total;

	total = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (!str[i])
				break ;
			conv_spec(str, &i, &flag, &ap);
			print_conversion(&flag, &ap);
			total += flag.total;
		}
		else
			print_one_char(str, &total, i);
		++i;
	}
	va_end(ap);
	return (total);
}	
