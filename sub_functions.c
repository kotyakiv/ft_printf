#include "ft_printf.h"

void	ft_putllnbr(long long n)
{
	char	c;

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

long long ft_bigger(long long a, long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long long ft_smaller(long long a, long long b)
{
	if (a < b && a >= 0)
		return (a);
	else
		return (b);
}

long long ft_abs(long long a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

void str_toupper(char *str)
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