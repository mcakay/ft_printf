/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:54 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_unsigned(t_print *print, unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_convert_unsigned(print, nb / 10, fd);
		ft_convert_unsigned(print, nb % 10, fd);
	}
	else
		ft_putchar_rtn(print, nb + 48, fd);
}

void	ft_convert_hex(t_print *print, unsigned int nb, int fd)
{
	int	add;

	add = 55;
	if (print->spec == 'x')
		add += 32;
	if (nb >= 16)
	{
		ft_convert_hex(print, nb / 16, fd);
		ft_convert_hex(print, nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_rtn(print, nb + 48, fd);
		else
			ft_putchar_rtn(print, nb + add, fd);
	}
}

void	ft_convert_p(t_print *print, unsigned long nb, int fd)
{
	if (nb >= 16)
	{
		ft_convert_p(print, nb / 16, fd);
		ft_convert_p(print, nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_rtn(print, nb + 48, fd);
		else
			ft_putchar_rtn(print, nb + 87, fd);
	}
}
