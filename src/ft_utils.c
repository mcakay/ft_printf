#include "ft_printf.h"

void	ft_null_control(t_print *print)
{
	if (print->spec == 's' && !print->sval)
	{
		print->sval = "(null)";
		print->null = 1;
	}
	if (print->spec == 'p' && !print->pval)
		print->null = 1;
}
