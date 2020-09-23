#include <stdio.h>
#include <stdlib.h>

#include "t4.h"

void eliminarRango(Nodo **phead, double y, double z){
    Nodo *p;
    p = *phead;
    Nodo *q;
    q = p;
    Nodo *dummy;
    int used = 0;
    while(q->x <= z){
        if(y <= q->x) {
            p = p->prox;
            free(q);
            if(used){
                dummy->prox = p;
            }
            else{
                *phead = p;
            }
            if (p == NULL) {
                break;
            }
            q = p;
        }
        else{
            dummy=p;
            used = 1;
            p = p->prox;
            q = p;
        }
    }
}
