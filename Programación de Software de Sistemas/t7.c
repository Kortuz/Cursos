#include <stdio.h>
#include <pthread.h>

char* compradorF = NULL;
char* vendedorF = NULL;
int precioF = 0;
int wait = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;

int vendo(int precio, char *vendedor, char *comprador){

    pthread_mutex_lock(&mutex);
    while (compradorF != NULL){
        pthread_cond_wait(&cond, &mutex);
    }
    wait++;
    if(precioF == 0 || precio < precioF){
        precioF = precio;
    } else{
        wait--;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        return  0;
    }
    while(compradorF == NULL && precioF == precio){
        pthread_cond_wait(&cond, &mutex);
    }
    if(precio != precioF){
        wait--;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        return 0;
    }wait--;printf("%s\n", vendedor);
    comprador = compradorF;
    vendedorF = vendedor;

    wait--;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
    return 1;

}

int compro(char *comprador, char *vendedor){

    pthread_mutex_lock(&mutex);
    if (precioF == 0){
        return 0;
    }
    compradorF = comprador;
    pthread_cond_broadcast(&cond);
    while(wait){
        pthread_cond_wait(&cond, &mutex);
    }
    vendedor = vendedorF;
    int miPrecio = precioF;
    compradorF = NULL;
    vendedorF = NULL;
    precioF = 0;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
    return miPrecio;
}