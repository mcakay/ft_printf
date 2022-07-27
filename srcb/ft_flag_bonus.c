/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:25 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 12:38:27 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_apply_flags(t_print *print)
{
	ft_calc_val_len(print);
	ft_null_control(print);
	if (print->precision)
		ft_apply_precision_flag(print);
	ft_sign_control(print);
	if (print->dash)
	{
		print->dash = print->width;
		print->width = 0;
	}
	else if (print->zero && !print->precision
		&& print->spec != 's' && print->spec != 'c')
	{
		print->zero_len = print->width;
		print->width = 0;
	}
	ft_apply_width_flag(print);
	ft_apply_zero_flag(print);
}

void	ft_check_flags(t_print *print, char *str)
{
	int	i;

	i = 0;
	while (*(str + i) && !ft_strchr("csdiupxX%%", *(str + i)))
	{
		if (*(str + i) == '#')
			ft_sharp_flag(print, &i);
		if (*(str + i) == ' ')
			ft_space_flag(print, &i);
		if (*(str + i) == '+')
			ft_plus_flag(print, &i, str);
		if (*(str + i) == '-')
			ft_dash_flag(print, &i);
		else if (*(str + i) == '0')
			ft_zero_flag(print, &i);
		if (ft_isdigit(*(str + i)))
			ft_width_flag(print, &i, str);
		if (*(str + i) == '.')
			ft_precision_flag(print, &i, str);
	}
	print->spec = *(str + i);
}
