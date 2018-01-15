
#include "bsm.h"

t_event bsm_get_new_event(int c)
{
    if (c == '+')
        return (EVENT_Add);
    else if (c == '-')
        return (EVENT_Sub);
    else if (c == '*' || c == '/' || c == '%')
        return (EVENT_Op);
    else if (c == '(')
        return (EVENT_Obrk);
    else if (c == ')')
        return (EVENT_Cbrk);
    else if (c == -1)
        return (EVENT_Eof);
    else
        return (EVENT_Dig);
}