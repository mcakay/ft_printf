/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:18:26 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/07 13:07:21 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_iterstr(const char *s, t_print **print, va_list args)
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
			ft_put(print, args);
			i += ft_strlen(str) - 1;
		}
		else
		{
			ft_putchar_rtn(print, *(s + i), 1);
			ft_reset_print(print);
		}
		i++;
	}
	free(str);
}

int		ft_printf(const char *s, ...)
{
	va_list args;
	t_print *print;
	
	print = malloc(sizeof(t_print));
	ft_reset_print(&print);
	print->return_val = 0;
	va_start(args, s);
	ft_iterstr(s, &print, args);
	va_end(args);
	free(print);
	return (print->return_val);
}