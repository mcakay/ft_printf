#include "ft_printf.h"

void	ft_precision_flag(t_print *print, int *i, char *str)
{
	print->precision = 1;
	(*i)++;
	while (!ft_strchr(" -+#.csdiupxX%%", *(str + *i)))
	{
		print->precision_len = (print->precision_len * 10) + (*(str + *i) - 48);
		(*i)++;
	}
}

void	ft_apply_precision_flag(t_print *print)
{
	if (print->spec == 'd' || print->spec == 'i' || print->spec == 'u'
		|| print->spec == 'x' || print->spec == 'X')
	{
		if (!print->dval && !print->uval && !print->xval
			&& !print->precision_len)
		{
			print->noprint = 1;
			print->val_len--;
		}
		if (print->dval < 0)
				print->val_len--;
		if (print->val_len < print->precision_len)
		{
			print->zero = 1;
			print->zero_len = print->precision_len;
		}
	}
	if (print->spec == 's' && !print->null)
	{
		if (print->val_len < print->precision_len)
			print->precision_len = print->val_len;
		print->val_len = print->precision_len;
	}
}
