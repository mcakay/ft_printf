#include "ft_printf.h"

void	ft_dash_flag(t_print *print, int *i)
{
	print->dash = 1;
	(*i)++;
}

void	ft_apply_dash_flag(t_print *print)
{
	int	i;

	i = 0;
	if (print->precision && print->precision_len > print->val_len)
		print->val_len = print->precision_len;
	if (print->precision && print->dval < 0)
		print->val_len++;
	while (i < print->dash - print->val_len)
	{
		ft_putchar_rtn(print, ' ', 1);
		i++;
	}
}
