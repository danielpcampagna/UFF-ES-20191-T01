#ifndef NOFIG_H
#define NOFIG_H

typedef struct no_figura {
    char tipo[3];
    void *figura;
} TNOFIG;

void libera_no_figura(TNOFIG *p);

#endif //NOFIG_H