#include <stdio.h>
#include <stdlib.h>

//#include "t2.h"

// insertar_bits(0b10 1101, 3, 0b00, 2) es 0b1010 0101
// insertar_bits(0b11 0111, 0, 0b011, 3) es 0b1 1011 1011
// insertar_bits(0b1 0111, 2, 0b01110, 5) es 0b10 1011 1011

typedef unsigned int uint;
uint insertar_bits(uint x, int pos, uint y, int len) {
    //Aquí clonamos el binario x en su estado inicial para mas tarde
    uint u=x;
    uint v=x;
    //Ahora borramos los primeros bits de x, tantos como el valor de pos, pues hay que ubicar y despues de estos
    x>>=pos;
    //Hacemos el espacio para y, de tamaño len
    x<<=len;
    //insertamos y
    x=x|y;
    //hacemos el espacio para los que van despues del y
    x<<=pos;
    //dejamos el u con solo ceros y los primeros bits a insertar
    v>>=pos;
    v<<=pos;
    u=v^u;
    //insertamos los primeros bits
    x=u|x;
    //devolvemos x
    return x;
}




