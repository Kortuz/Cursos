#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "t3.h"

//... programe aca recorte y recortar ...

char *recorte(char *str){
    int l = strlen(str);
    char *r = malloc(l* sizeof(char));

    char *p;
    char *q;
    char *x;

    p = str;
    q = r;
    x = r;

    int a = 0;
    int b = 0;

    while(*p){
        if(*p == ' ' && a){
            *r = *p;
            r++;
        }
        if(*p != ' '){
            a = 1;
            *r = *p;
            r++;
            b++;
        }
        p++;
    }

    while(b){
        if(*q != ' '){
            b--;
        }
        q++;
        if(!b){
            *q = '\0';
        }
    }
    return x;
}


void recortar(char **pstr){
    char *p = *pstr;
    char *q = *pstr;
    char *a;
    while(*p) {
        if (*p != ' ') {
            q = p;
            a=p;
            *pstr = a;
            break;
        }
        else {
            p++;
        }
        if(!*p){
            *q='\0';
        }
    }

    while(*p){
        if(*p == ' '){
            p++;
        }
        else{
            p++;
            q = p;
        }
    }
    *q = '\0';
}


