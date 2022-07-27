/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:18:05 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:41:44 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_print(t_print *print)
{
	print->spec = 0;
	print->cval = 0;
	print->uval = 0;
	print->sval = 0;
	print->dval = 0;
	print->xval = 0;
	print->pval = 0;
}
