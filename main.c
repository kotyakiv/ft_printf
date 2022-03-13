#include <stdio.h>
#include "ft_printf.h"

int main()
{
	double a = 990090.095994849;
	int b;

	b = printf("%.2f\n", a);
	printf("%d\n", b);
	b = ft_printf("%.2f\n", a);
	printf("%d\n", b);

	return 0;
}
