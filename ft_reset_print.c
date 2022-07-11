#include "ft_printf.h"

void    ft_reset_print(t_print **print)
{
    (*print)->zero = 0;
    (*print)->zero_len = 0;
    (*print)->precision = 0;
    (*print)->precision_len = 0;
    (*print)->dash = 0;
    (*print)->space = 0;
    (*print)->sharp = 0;
    (*print)->plus = 0;
    (*print)->width = 0;
    (*print)->spec = 0;
    (*print)->val_len = 0;
    (*print)->cval = 0;
    (*print)->uval = 0;
    (*print)->sval = 0;
    (*print)->dval = 0;
    (*print)->xval = 0;
    (*print)->pval = 0;
    (*print)->null = 0;
    (*print)->noprint = 0;
}