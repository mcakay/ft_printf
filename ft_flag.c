/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:40:24 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 13:40:03 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_flags(t_print **print)
{
	if ((*print)->zero)
		ft_apply_zero_flag(print);
	else if ((*print)->number)
		ft_apply_number_flag(print);
}

void	ft_check_flags(t_print **print, char *str)
{
	int		i;

	i = 0;
	while (*(str + i) && !ft_isidentifier(*(str + i)))
	{
		if (*(str + i) == '-')
			ft_dash_flag(print, &i, str);
		if (*(str + i) == '0' && !((*print)->dash))
			ft_zero_flag(print, &i, str);
		if (*(str + i) == '.')
			ft_dot_flag(print, &i, str);
		if (*(str + i) == '#')
			ft_sharp_flag(print);
		if (*(str + i) == ' ' && !((*print)->plus))
			ft_space_flag(print);
		if (*(str + i) == '+')
			ft_plus_flag(print);
		if (ft_isdigit(*(str + i)) && (*print)->zero == 0)
			ft_number_flag(print, &i, str);
	}
	ft_check_identifier(print, str, &i);
}