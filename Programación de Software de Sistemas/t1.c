#include <stdio.h>
#include <stdlib.h>

void rotar(int A[], int n){
    int x=A[1]; // almacenamos el segundo elemento
    for(int i = 1; i <= n-1; i++){ // empezamos desde el segundo elemento
        if(i!=n-1){ // movemos los elementos 1 hacia la derecha si el elemento no es el último
            int y=A[i+1];
            A[i+1]=x;
            x=y;
        }
        else{   // si es el último lo ponemos en el primero
            A[1]=x;
        }
    }
}

int main(int argc, char *argv[ ]) {
    int n = atoi(argv[1]);
    int A[n];
    int *p;
    p=A; // definimos un puntero para avanzar por el arreglo
    for(int i = 0; i < n - 1; i++){ // enfrentamientos para cada semana
        for(int i = 0; i < n; i++){ // definimos el arreglo de 0
            A[i]=i+1;
        }
        int a = i;  // usamos una variable que nos indica en que semana es
        while(a>0){ // rotamos primero el arreglo tantas veces como el numero de semana-1
            rotar(A, n);
            a--;
        }

        for (int j = 0; j <= n ; j = j + 2) { // enfrentamos los equipos
            rotar(p, n - j);
            p = p + 2;
        }
        p=A;
        printf("Semana %d: ", i+1);
        for (int z = 0; z < n; z++) {// imprimirmos los arreglos con el guión o espacio según corresponda
            if(z % 2 == 0) {
                printf("%d-", A[z]);
            }
            else{
                printf("%d ", A[z]);
            }
        }
        printf("\n");
    }
    return 0;
}




