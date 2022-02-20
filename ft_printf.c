/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:51:09 by ykot              #+#    #+#             */
/*   Updated: 2022/02/16 17:00:19 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
	t_flags	flag;
    int i;
    int total;

    total = 0;
    i = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ++i;
			if (!str[i])
				break;
			conversion_specification(str, &i, &flag, &ap);
			print_conversion(&flag, &ap);
			total += flag.total;
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
