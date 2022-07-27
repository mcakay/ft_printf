/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:31 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:18:33 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print(const char *s, t_print *print, va_list args)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = 0;
	while (*(s + i))
	{
		j = 0;
		if (*(s + i) == '%')
		{
			i++;
			while (!ft_strchr("cspdiuxX%%", *(s + i + j)))
				j++;
			str = ft_substr(s + i, 0, j + 1);
			ft_check_flags(print, str);
			ft_puts(print, args);
			i += ft_strlen(str) - 1;
			free(str);
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
