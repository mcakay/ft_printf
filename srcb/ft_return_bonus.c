#include "ft_printf_bonus.h"

void	ft_putchar_rtn(t_print *print, char c, int fd)
{
	ft_putchar_fd(c, fd);
	print->return_val++;
}

void	ft_putstr_rtn(t_print *print, char *str, int fd)
{
	int	i;

	i = 0;
	if (print->precision && print->spec == 's')
	{
		if (print->null && print->precision_len < print->val_len)
		{
			print->return_val = print->width;
			return ;
		}
		while (i < print->precision_len && *(str + i))
		{
			ft_putchar_rtn(print, *(str + i), fd);
			i++;
		}
		return ;
	}
	ft_putstr_fd(str, fd);
	print->return_val += ft_strlen(str);
}

void	ft_putnbr_rtn(t_print *print, int nb, int fd)
{
	char	*str;

	if (nb == -2147483648 && print->zero)
	{
		ft_putstr_rtn(print, "2147483648", fd);
		return ;
	}
	if (nb < 0 && print->zero)
		nb *= -1;
	if (print->plus && print->zero && (print->dval > 0 || print->uval > 0)
		&& print->precision)
		ft_putchar_rtn(print, '+', 1);
	str = ft_itoa(nb);
	if (!print->noprint)
		ft_putstr_rtn(print, str, fd);
	free(str);
}
