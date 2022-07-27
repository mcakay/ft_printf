/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:18:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:57 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_rtn(t_print *print, char c, int fd)
{
	ft_putchar_fd(c, fd);
	print->return_val++;
}

void	ft_putstr_rtn(t_print *print, char *str, int fd)
{
	ft_putstr_fd(str, fd);
	print->return_val += ft_strlen(str);
}

void	ft_putnbr_rtn(t_print *print, int nb, int fd)
{
	char	*str;

	str = ft_itoa(nb);
	ft_putstr_rtn(print, str, fd);
	free(str);
}
