#include <stdio.h>
#include <pthread.h>


typedef unsigned long long Set;
Set buscarSequencialmente(int *a, int n, int j, int step) {
    Set comb = (1 << (n - 1) << 1) - 1; // 2n-1: nº de combinaciones
    for (Set k = 1 + j; (k <= step + j) & (k <= comb) ; k++) {  // buscar en el rango del step y dentro de 2n-1
        // k es el mapa de bits para el subconjunto { a[i] | bit ki de k es 1 }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (k & ((Set) 1 << i)){// si bit ki de k es 1
                sum += a[i];
            }
        }
        if (sum == 0) {  // éxito: el subconjunto suma 0
            return k;    // y el mapa de bits para el subconjunto es k
        }
    }
    return 0;        // no existe subconjunto que sume 0
}

typedef  struct{
    int* a;
    int n;
    Set j;
    Set step;
    Set k;  // para guardar la solución si existe
}   Args;

void *thread_function(void *params){
    Args *p = (Args *) params;
    int* a = p->a;
    int n = p->n;
    int j = p->j;
    int step = p->step;
    p->k = buscarSequencialmente(a, n, j, step);
    return NULL;
}

// Función  principal
Set  buscar(int *a, int n){
    pthread_t  t[8] ;
    Args  args [8] ;
    Set  f;
    for(int  k = 0;  k<8;  k++){
        args[k].a = a;
        args[k].n = n;
        Set comb = (1 << (n - 1) << 1) / 8; // 2n / 8: nº de combinaciones
        args[k].j = k*comb;
        args[k].step = comb;

        //  lanzar  thread
        pthread_create(&t[k] , NULL,  thread_function , &args[k]) ;
    }
    //  espera los threads
    for(int k = 0; k<8; k++) {
        pthread_join(t[k], NULL);
        if( args[k].k !=  0){
            f = args[k].k ;  //  recupero  k si existe
            return  f;
        }
    }
    return  0;  // devuelvo 0 si no existe solución
}
