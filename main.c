#include <stdio.h>

int ft_printf(const char *str, ...);

int main()
{
	int a = printf("{%*3d}", 5, 0);
	printf("%d\n", a);
	a = ft_printf("{%*3d}", 5, 0);
	printf("%d\n", a);
	return 0;
}