/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:34 by mcakay            #+#    #+#             */
/*   Updated: 2022/07/25 12:33:51 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int				zero;
	int				zero_len;
	int				precision;
	int				precision_len;
	int				dash;
	int				space;
	int				sharp;
	int				plus;
	int				width;
	char			spec;
	int				val_len;
	int				cval;
	char			*sval;
	long			dval;
	unsigned int	uval;
	unsigned int	xval;
	unsigned long	pval;
	int				return_val;
	int				noprint;
}	t_print;

int		ft_printf(const char *s, ...);
void	ft_reset_print(t_print *print);
void	ft_print(const char *s, t_print *print, va_list args);
void	ft_check_flags(t_print *print, char *str);
void	ft_puts(t_print *print, va_list args);
void	ft_putchar_rtn(t_print *print, char c, int fd);
void	ft_putstr_rtn(t_print *print, char *str, int fd);
void	ft_putnbr_rtn(t_print *print, int nb, int fd);
int		ft_calc_size(int nb);
void	ft_dash_flag(t_print *print, int *i);
void	ft_zero_flag(t_print *print, int *i);
void	ft_width_flag(t_print *print, int *i, char *str);
void	ft_precision_flag(t_print *print, int *i, char *str);
void	ft_plus_flag(t_print *print, int *i, char *str);
void	ft_calc_val_len(t_print *print);
void	ft_apply_flags(t_print *print);
void	ft_apply_dash_flag(t_print *print);
void	ft_apply_width_flag(t_print *print);
void	ft_apply_zero_flag(t_print *print);
void	ft_apply_precision_flag(t_print *print);
void	ft_convert_unsigned(t_print *print, unsigned int nb, int fd);
void	ft_puts2(t_print *print, va_list args);
void	ft_convert_hex(t_print *print, unsigned int nb, int fd);
void	ft_calc_size_hex(t_print *print, unsigned int nb);
void	ft_convert_p(t_print *print, unsigned long nb, int fd);
void	ft_calc_size_p(t_print *print, unsigned long nb);
void	ft_puts3(t_print *print, va_list args);
void	ft_null_control(t_print *print);
void	ft_sign_control(t_print *print);
int		ft_calc_size_unsigned(unsigned int nb);
void	ft_sharp_flag(t_print *print, int *i);
void	ft_space_flag(t_print *print, int *i);
#endif