#include "ft_printf.h"

int main()
{
	int a[] = {1, 2, 3, 4, 5};

	ft_printf("%%abc%15.26cdef%-+s12\n", '!', "MaMa");
	ft_printf("%p\n", a);
	ft_printf("%d\t%i\n", 15, 50);
	ft_printf("%o\t%x\t%X\n", 350, 350, 350);
	printf("%o\t%x\t%X\n", 350, 350, 350);
	return 0;
}