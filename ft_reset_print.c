/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:26:13 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 00:13:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_print(t_print **print)
{
	(*print)->zero = 0;
	(*print)->zero_len = 0;
	(*print)->dot = 0;
	(*print)->dot_len = 0;
	(*print)->dash = 0;
	(*print)->dash_len = 0;
	(*print)->space = 0;
	(*print)->sharp = 0;
	(*print)->plus = 0;
	(*print)->number = 0;
	(*print)->conv = 0;
	(*print)->cval = 0;
	(*print)->sval = 0;
	(*print)->dval = 0;
	(*print)->uval = 0;
	(*print)->pval = 0;
	(*print)->hexval = 0;
	(*print)->xval = 0;
}