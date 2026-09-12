#include "bits.h"

int obtenerFicha(unsigned char* datos, int bitInicial){
    int byte = bitInicial / 8;
    int offset = bitInicial % 8;

    if(offset <=5 ){
        int ficha = (datos[byte] >> offset) & 7;

        return ficha;
    }
    else{
        int parte1 = (datos[byte] >> 6) & 3;
        int parte2 = datos[byte + 1] & 1;

        int ficha = parte1 | (parte2 << 2);

        return ficha;
    }
}