#include <stdlib.h>

#include "no_figura.h"

void libera_no_figura(TNOFIG *p)
{
    if (p)
    {
        if (p->figura)
            free(p->figura);
        free(p);
    }
}