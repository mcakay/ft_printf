#include "ft_printf.h"

void	ft_plus_flag(t_print **print, int *i, char *str)
{
	(*print)->plus = 1;
	(*i)++;
	while (*(str + *i) == '+')
		(*i)++;
}