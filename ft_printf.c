#include "ft_printf.h"

void init_params(t_params *params)
{
    params->justify = false;
    params->plus_neg = false;
    params->spaced = false;
    params->hash = false;
    params->pad = false;
    params->wid_len = 0;
    params->num_len = 0;
    params->p_wildcard = false;
    params->buff = NULL;
    params->specifier = 0;
    params->modifer = 0;
}