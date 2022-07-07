/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:28:16 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 13:07:19 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isidentifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' 
	|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

void	ft_check_identifier(t_print **print, char *str, int *i)
{
	if (*(str + *i) == 'c')
		(*print)->conv = 'c';
	if (*(str + *i) == 's')
		(*print)->conv = 's';
	if (*(str + *i) == 'd')
		(*print)->conv = 'd';
	if (*(str + *i) == 'i')
		(*print)->conv = 'i';
	if (*(str + *i) == 'u')
		(*print)->conv = 'u';
	if (*(str + *i) == 'x')
		(*print)->conv = 'x';
	if (*(str + *i) == 'p')
		(*print)->conv = 'p';
	if (*(str + *i) == 'X')
		(*print)->conv = 'X';
	if (*(str + *i) == '%')
		(*print)->conv = '%';
}