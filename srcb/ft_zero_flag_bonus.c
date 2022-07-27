/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:52 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:51 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_zero_flag(t_print *print, int *i)
{
	print->zero = 1;
	(*i)++;
}

void	ft_apply_zero_flag(t_print *print)
{
	int	i;

	i = 0;
	if (print->dval < 0 && print->zero)
	{
		print->zero_len++;
		print->val_len++;
		ft_putchar_rtn(print, '-', 1);
	}
	while (i < print->zero_len - print->val_len)
	{
		ft_putchar_rtn(print, '0', 1);
		i++;
	}
}
