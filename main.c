#include "ft_printf.h"

int main()
{
	double arg = -1067.359999;
	printf("STD\t%lf\n", arg);
	ft_printf("MY\t%lf\n", arg);
	printf("\n");

	arg = 458.356000;
	printf("STD\t%lf\n", arg);
	ft_printf("MY\t%lf\n", arg);
	return 0;
}
