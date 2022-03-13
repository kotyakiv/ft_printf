#include <stdio.h>
#include "ft_printf.h"

int main()
{
	double a = 990090.095994849;
	int b;

	/*b = printf("%.214748f\n", a);
	printf("%d\n", b);*/
	b = ft_printf("%21474836475f\n", a);
	printf("%d\n", b);

	return 0;
}
