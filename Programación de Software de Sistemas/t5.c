#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char izq[10], der[10], llave[20], val[59], newline;
} Definicion;

int main(int argc, char *argv[]) {

    char* dicc = argv[1];
    char* llave = argv[2];

    FILE *fp;
    fp = fopen(dicc, "r");


    if (fp == NULL) {
        perror(dicc);
        exit(1);
    }

    if (fseek(fp, 0, SEEK_END) !=0){
        perror(dicc);
        exit(1);
    }

    Definicion *buf = malloc(sizeof(Definicion));
    int line = 0;

    fseek(fp, (long) (sizeof(Definicion) * line), SEEK_SET);
    fread(buf, sizeof(Definicion),1, fp);

    while(1){
        if(strncmp(llave, buf->llave, strlen(llave)) == 0){
            printf("%.59s\n", buf->val);
            break;
        }
        else if(strncmp(llave, buf->llave, strlen(llave)) > 0){
            int derecha = atoi(buf->der);
            if(derecha == -1){
                printf("palabra no encontrada\n");
                break;
            }
            line = derecha;
        }
        else{
            int izquierda = atoi(buf->izq);
            if(izquierda == -1){
                printf("palabra no encontrada\n");
                break;
            } else if (strncmp(llave, buf->llave, strlen(llave)) < 0){
                line = izquierda;
            }
        }

        fseek(fp, (long)sizeof(Definicion) * line, SEEK_SET);
        fread(buf, sizeof(Definicion),1, fp);
    }
    fclose(fp);
    return 0;
}
