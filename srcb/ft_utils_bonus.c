/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 15:32:00 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_sign_control(t_print *print)
{
	if (print->plus)
		print->val_len++;
	if (print->plus && !print->precision && print->dval >= 0
		&& print->spec == 'd')
		ft_putchar_rtn(print, '+', 1);
	else if (print->plus && !print->precision && print->dval >= 0
		&& print->spec == 'i')
		ft_putchar_rtn(print, '+', 1);
	else if (print->plus && !print->precision && print->spec == 'u')
		ft_putchar_rtn(print, '+', 1);
	if (print->space && !print->precision && print->dval >= 0
		&& print->spec == 'd')
		ft_putchar_rtn(print, ' ', 1);
	else if (print->space && !print->precision && print->dval >= 0
		&& print->spec == 'i')
		ft_putchar_rtn(print, ' ', 1);
	else if (print->space && !print->precision && print->spec == 'u')
		ft_putchar_rtn(print, ' ', 1);
}

void	ft_null_control(t_print *print)
{
	if (print->spec == 's' && !print->sval)
	{
		print->sval = "(null)";
		print->val_len = 6;
	}
}

void	ft_calc_val_len(t_print *print)
{
	if (print->spec == 'c' || print->spec == '%')
		print->val_len = 1;
	if (print->spec == 's' && print->sval)
		print->val_len = ft_strlen(print->sval);
	if (print->spec == 'd' || print->spec == 'i')
		print->val_len = ft_calc_size(print->dval);
	if (print->spec == 'u')
		print->val_len = ft_calc_size_unsigned(print->uval);
	if (print->spec == 'x' || print->spec == 'X')
		ft_calc_size_hex(print, print->xval);
	if (print->spec == 'p')
	{
		ft_calc_size_p(print, print->pval);
		print->val_len += 2;
	}
}
