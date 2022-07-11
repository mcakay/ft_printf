#include "ft_printf.h"

void    ft_space_flag(t_print **print, int *i)
{
    (*print)->space = 1;
    (*i)++;
}