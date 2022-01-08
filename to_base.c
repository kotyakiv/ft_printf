#include "ft_printf.h"

void ft_str_rev(char *str)
{
	int i;
	int l;
	char temp;

	l = ft_strlen(str);
	i = 0;
	while (i < l / 2)
	{
		temp = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = temp;
		++i;
	}
}

int num_digit(long long  num, int base)
{
	int i;

	i = 0;
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}

char ft_digit(long long  num, int base)
{
	char digit;

	if (num % base > 9)
		digit = 'a' + num % base - 10;
	else
		digit = num % base + '0';
	return (digit);
}


char *dem_to_base(long long num, int base)
{
	char *total;
	int iter;
	int i;
	char digit;

	iter = num_digit(num, base);
	total = ft_strnew(iter);
	i = 0;
	while (i < iter)
	{
		digit = ft_digit(num, base);
		total[i] = digit;
		num /= base;
		++i;
	}
	ft_str_rev(total);
	return total;
}
