#include "ft_printf.h"

void	ft_width_flag(t_print *print, int *i, char *str)
{
	while (!ft_strchr(" -+#.csdiupxX%%", *(str + *i)))
	{
		print->width = (print->width * 10) + (*(str + *i) - 48);
		(*i)++;
	}
}

void	ft_apply_width_flag(t_print *print)
{
	int	i;

	i = 0;
	if (print->dval < 0 && print->zero)
		print->width--;
	if (print->precision && print->precision_len > print->val_len)
	{
		print->width -= print->precision_len;
		print->width += print->val_len;
	}
	while (i < print->width - print->val_len)
	{
		ft_putchar_rtn(print, ' ', 1);
		i++;
	}
}
