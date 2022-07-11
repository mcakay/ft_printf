#include "ft_printf.h"

int ft_calc_size(int nb)
{
    int	counter;
	long	nbr;

	nbr = nb;
	counter = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		counter++;

		
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

int ft_calc_size_unsigned(unsigned int nb)
{
    int	counter;

	counter = 0;
	while (nb >= 10)
	{
		nb /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

void	ft_calc_size_hex(t_print **print, unsigned int nb)
{
	if (nb >= 16)
	{
		ft_calc_size_hex(print, nb / 16);
		ft_calc_size_hex(print, nb % 16);
	}
	else
		(*print)->val_len++;
}

void	ft_calc_size_p(t_print **print, unsigned long nb)
{
	if (nb >= 16)
	{
		ft_calc_size_p(print, nb / 16);
		ft_calc_size_p(print, nb % 16);
	}
	else
		(*print)->val_len++;
}