/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:31:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 13:07:20 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert0(t_print **print, unsigned long nb)
{
	if (nb >= 16)
	{
		ft_convert0(print, nb / 16);
		ft_convert0(print, nb % 16);
	}
	else
		(*print)->hexval++;
}

void	ft_convert1(t_print **print, unsigned long nb)
{
	if (nb >= 16)
	{
		ft_convert1(print, nb / 16);
		ft_convert1(print, nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar_rtn(print, nb + 48, 1);
		else
			ft_putchar_rtn(print, nb + 87, 1);
	}
}

void	ft_convert2(t_print **print, unsigned long nb)
{
	if (nb >= 16)
	{
		ft_convert2(print, nb / 16);
		ft_convert2(print, nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar_rtn(print, nb + 48, 1);
		else
			ft_putchar_rtn(print, nb + 55, 1);
	}
}

