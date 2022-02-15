/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:47:22 by ykot              #+#    #+#             */
/*   Updated: 2022/02/15 15:47:45 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putllnbr(long long n)
{
	char	c;

	if (n == -9223372036854775807 - 1)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putllnbr(n / 10);
	c = n % 10 + '0';
	ft_putchar(c);
}

void	ft_putllunbr(unsigned long long n)
{
	char	c;

	if (n >= 10)
		ft_putllunbr(n / 10);
	c = n % 10 + '0';
	ft_putchar(c);
}

long long	ft_bigger(long long a, long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long long	ft_smaller(long long a, long long b)
{
	if (a < b && a >= 0)
		return (a);
	else
		return (b);
}

void	str_toupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = ft_toupper(str[i]);
		++i;
	}
}
