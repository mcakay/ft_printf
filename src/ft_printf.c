/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:56 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *s, t_print *print, va_list args)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '%')
		{
			i++;
			print->spec = *(s + i);
			ft_puts(print, args);
			ft_reset_print(print);
		}
		else
			ft_putchar_rtn(print, *(s + i), 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_print	*print;

	print = malloc(sizeof(t_print));
	ft_reset_print(print);
	print->return_val = 0;
	va_start(args, s);
	ft_print(s, print, args);
	va_end(args);
	free(print);
	return (print->return_val);
}
