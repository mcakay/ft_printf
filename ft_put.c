/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:53:16 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 14:26:47 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put(t_print **print, va_list args)
{
	if ((*print)->conv == 'c')
		(*print)->cval = va_arg(args, int);
	else if ((*print)->conv == 's')
		(*print)->sval = va_arg(args, char *);
	else if ((*print)->conv == 'd' || (*print)->conv == 'i')
		(*print)->dval = va_arg(args, int);
	else if ((*print)->conv == 'u')
		(*print)->uval = va_arg(args, unsigned int);
	else if ((*print)->conv == 'p')
	{
		(*print)->pval = va_arg(args, unsigned long);
		ft_putstr_rtn(print, "0x", 1);
	}
	else if ((*print)->conv == 'x' || (*print)->conv == 'X')
		(*print)->xval = va_arg(args, unsigned int);
	else if ((*print)->conv == '%')
		(*print)->cval = '%';
	ft_apply_flags(print);
	if (!(*print)->dot)
		ft_put2(print);
}

void	ft_put2(t_print **print)
{
	if ((*print)->conv == 'c')
		ft_putchar_rtn(print, (*print)->cval, 1);
	else if ((*print)->conv == 's')
		ft_putstr_rtn(print, (*print)->sval, 1);
	else if ((*print)->conv == 'd' || (*print)->conv == 'i')
		ft_putnbr_rtn(print, (*print)->dval, 1);
	else if ((*print)->conv == 'u')
		ft_putnbr_rtn(print, (*print)->uval, 1);
	else if ((*print)->conv == 'x')
		ft_convert1(print, (*print)->xval);
	else if ((*print)->conv == 'X')
		ft_convert2(print, (*print)->xval);	
	else if ((*print)->conv == 'p')
		ft_convert1(print, (*print)->pval);	
	else if ((*print)->conv == '%')
		ft_putchar_rtn(print, '%', 1);
	if ((*print)->dash)
		ft_apply_dash_flag(print);	
}