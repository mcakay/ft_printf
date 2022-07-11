#include "ft_printf.h"

void    ft_sharp_flag(t_print **print, int *i)
{
    (*print)->sharp = 1;
    (*i)++;
}