/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:27 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_plus_flag(t_print *print, int *i, char *str)
{
	print->plus = 1;
	(*i)++;
	while (*(str + *i) == '+')
		(*i)++;
}
