#include <stdio.h>

int ft_printf(const char *str, ...);

int main()
{
	//int a;

	printf("%f\n", 5.00001);
    ft_printf("%f\n", 5.00001);
	return 0;
}
