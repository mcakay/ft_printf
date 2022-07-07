#include <stdio.h>
#include "ft_printf.h"

int	main()
{	
	int a = 42;
	//ft_printf(" %c %c %c", '0', '0', '1');
	ft_printf("%010da\n", -42);
	printf("%010da\n", -42);
	//system("leaks a.out");
}