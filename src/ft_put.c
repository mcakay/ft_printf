/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:18:03 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:42:04 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puts(t_print *print, va_list args)
{
	if (print->spec == 'c')
	{
		print->cval = va_arg(args, int);
		ft_putchar_rtn(print, print->cval, 1);
	}
	else if (print->spec == 's')
	{
		print->sval = va_arg(args, char *);
		ft_null_control(print);
		ft_putstr_rtn(print, print->sval, 1);
	}
	else if (print->spec == 'd' || print->spec == 'i')
	{
		print->dval = va_arg(args, int);
		ft_putnbr_rtn(print, print->dval, 1);
	}
	else
		ft_puts2(print, args);
}

void	ft_puts2(t_print *print, va_list args)
{
	if (print->spec == 'u')
	{
		print->uval = va_arg(args, unsigned int);
		ft_convert_unsigned(print, print->uval, 1);
	}
	else if (print->spec == 'x' || print->spec == 'X')
	{
		print->xval = va_arg(args, unsigned int);
		ft_convert_hex(print, print->xval, 1);
	}
	else
		ft_puts3(print, args);
}

void	ft_puts3(t_print *print, va_list args)
{
	if (print->spec == 'p')
	{
		print->pval = va_arg(args, unsigned long);
		ft_putstr_rtn(print, "0x", 1);
		ft_convert_p(print, print->pval, 1);
	}
	else if (print->spec == '%')
		ft_putchar_rtn(print, '%', 1);
}
