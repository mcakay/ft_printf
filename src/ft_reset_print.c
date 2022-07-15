#include "ft_printf.h"

void	ft_reset_print(t_print *print)
{
	print->spec = 0;
	print->cval = 0;
	print->uval = 0;
	print->sval = 0;
	print->dval = 0;
	print->xval = 0;
	print->pval = 0;
	print->null = 0;
}
