/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:51:09 by ykot              #+#    #+#             */
/*   Updated: 2022/02/15 15:51:11 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
	t_flags	flag;
    int i;
    int total;
    int result;

    total = 0;
    i = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
			if (str[i + 1] == '%')
			{
				ft_putchar('%');
                i += 2;
                total++;
				continue;
			}
            ++i;
            result = conversion_specification(str, &i, &flag, &ap);
            if (!result)
            {
                print_conversion(&flag, &ap);
                total += flag.total;
            }
            else if (result == 1)
                return (-1);
        }
        else
        {
			ft_putchar(str[i]);
            total++;
        }
        ++i;
    }
    va_end(ap);
    return (total);
}
