/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:18:01 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 11:41:39 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_print
{
	char			spec;
	char			cval;
	char			*sval;
	long			dval;
	unsigned int	uval;
	unsigned int	xval;
	unsigned long	pval;
	int				return_val;
}	t_print;

int		ft_printf(const char *s, ...);
void	ft_reset_print(t_print *print);
void	ft_print(const char *s, t_print *print, va_list args);
void	ft_puts(t_print *print, va_list args);
void	ft_putchar_rtn(t_print *print, char c, int fd);
void	ft_putstr_rtn(t_print *print, char *str, int fd);
void	ft_putnbr_rtn(t_print *print, int nb, int fd);
void	ft_convert_unsigned(t_print *print, unsigned int nb, int fd);
void	ft_puts2(t_print *print, va_list args);
void	ft_convert_hex(t_print *print, unsigned int nb, int fd);
void	ft_convert_p(t_print *print, unsigned long nb, int fd);
void	ft_puts3(t_print *print, va_list args);
void	ft_null_control(t_print *print);
#endif