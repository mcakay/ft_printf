/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 03:41:49 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 14:28:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_dash_flag(t_print **print, int *i, char *str)
{
	(*print)->dash = 1;
	(*i)++;
	while (!ft_strchr("+# .", *(str + *i)) && !ft_isidentifier(*(str + *i)))
	{
		(*print)->dash_len = ((*print)->dash_len * 10) + (*(str + *i) - 48);
		(*i)++;
	}
}

void	ft_apply_dash_flag(t_print **print)
{
	
	if ((*print)->conv == 'c')
		ft_print_dash(print, (*print)->dash_len - 1);
	if ((*print)->conv == 's')
		ft_print_dash(print, (*print)->dash_len - ft_strlen((*print)->sval));
	if ((*print)->conv == 'd' || (*print)->conv == 'i')
		ft_print_dash(print, (*print)->dash_len - ft_calc_size((*print)->dval));
	if ((*print)->conv == 'u')
		ft_print_dash(print, (*print)->dash_len - ft_calc_size((*print)->uval));
	if ((*print)->conv == 'x' || (*print)->conv == 'X')
	{
		ft_convert0(print, (*print)->xval);
		ft_print_dash(print, (*print)->dash_len - (*print)->hexval);
	}
	if ((*print)->conv == 'p')
	{
		ft_convert0(print, (*print)->pval);
		ft_print_dash(print, (*print)->dash_len - (*print)->hexval - 2);
	}
	if ((*print)->conv == '%')
		ft_print_dash(print, (*print)->dash_len - 1);
}

void	ft_print_dash(t_print **print, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_rtn(print, ' ', 1);
		i++;
	}
}