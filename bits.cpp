#include "bits.h"

int obtenerFicha(unsigned char* datos, int bitInicial)
{
    int byte = bitInicial / 8;
    int offset = bitInicial % 8;

    if (offset <= 5)
    {
        int ficha = (datos[byte] >> offset) & 7;

        return ficha;
    }
    else if (offset == 6){
        int parte1 = (datos[byte] >> 6) & 3;
        int parte2 = datos[byte + 1] & 1;

        int ficha = parte1 | (parte2 << 2);

        return ficha;
    }
    else{
        int parte1 = (datos[byte] >> 7) & 1;
        int parte2 = datos[byte + 1] & 3;

        int ficha = parte1 | (parte2 << 1);

        return ficha;
    }
}

void ponerFicha(unsigned char* datos, int bitInicial, int ficha){
    int byte = bitInicial / 8;
    int offset = bitInicial % 8;

    if (offset <= 5){
        datos[byte] &= ~(7 << offset);
        datos[byte] |= (ficha << offset);
    }
    else if (offset == 6){
        datos[byte] &= ~(3 << 6);
        datos[byte + 1] &= ~1;

        datos[byte] |= (ficha & 3) << 6;
        datos[byte +1] |= (ficha >> 2);
    }else{
        datos[byte] &= ~(1 << 7);
        datos[byte + 1] &= ~3;

        datos[byte] |= (ficha & 1) << 7;
        datos[byte + 1] |= (ficha >> 1);
    }
}

void marcarPosicion(unsigned char* marcas, int indice)
{
    int byte = indice / 8;
    int bit = indice % 8;

    marcas[byte] |= (1 << bit);
}

bool estaMarcada(unsigned char* marcas, int indice)
{
    int byte = indice / 8;
    int bit = indice % 8;

    return (marcas[byte] & (1 << bit)) != 0;
}






