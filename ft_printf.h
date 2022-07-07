#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
typedef struct s_print
{
	int				zero;
	int				zero_len;
	int				dot;
	int				dot_len;
	int				dash;
	int				dash_len;
	int				space;
	int				sharp;
	int				plus;
	int				number;
	int				number_len;
	int				return_val;
	char			cval;
	char			*sval;
	int				dval;
	unsigned int	uval;
	unsigned long	pval;
	int				hexval;
	unsigned int	xval;
	char			conv;
} t_print;

int		ft_printf(const char *s, ...);
void	ft_reset_print(t_print **print);
void	ft_iterstr(const char *s, t_print **print, va_list args);
void	ft_check_flags(t_print **print, char *str);
void	ft_apply_flags(t_print **print);
void	ft_put(t_print **print, va_list args);
void	ft_put2(t_print **print);
void	ft_dash_flag(t_print **print, int *i, char *str);
void	ft_dot_flag(t_print **print, int *i, char *str);
void	ft_number_flag(t_print **print, int *i, char *str);
void	ft_plus_flag(t_print **print);
void	ft_sharp_flag(t_print **print);
void	ft_space_flag(t_print **print);
void	ft_zero_flag(t_print **print, int *i, char *str);
void	ft_check_identifier(t_print **print, char *str, int *i);
int		ft_isidentifier(char c);
void	ft_apply_zero_flag(t_print **print);
void	ft_print_zero(t_print **print, int	size);
int		ft_calc_size(long nb);
void	ft_putchar_rtn(t_print **print, char c, int fd);
void	ft_putstr_rtn(t_print **print, char *str, int fd);
void	ft_putnbr_rtn(t_print **print, int nb, int fd);
void	ft_convert0(t_print **print, unsigned long nb);
void	ft_convert1(t_print **print, unsigned long nb);
void	ft_convert2(t_print **print, unsigned long nb);
void	ft_apply_number_flag(t_print **print);
void	ft_print_number(t_print **print, int	size);
void	ft_apply_dash_flag(t_print **print);
void	ft_print_dash(t_print **print, int size);
void	ft_apply_dot_flag(t_print **print);
void	ft_print_dot(t_print **print, int	size);
#endif