#include "ft_printf.h"

void ft_strrev(char *str)
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

	iter = num_digit(num, base);
	total = ft_strnew(iter);
	i = 0;
	while (i < iter)
	{
		total[i] = ft_digit(num, base);
		num /= base;
		++i;
	}
	ft_strrev(total);
	return total;
}
