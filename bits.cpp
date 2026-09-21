#include "bits.h"

int obtenerFicha(unsigned char* datos, int bitInicial){                                      ///Resive la memoria donde esta guardado el tablero y la posicion del primer bite de una ficha
    int byte = bitInicial / 8; ///dividimos entre 8 porque 1 byte = 8 bits                      y devuelve el numero de esa ficha (0-7)
    int offset = bitInicial % 8; ///

    if (offset <= 5){
        int ficha = (datos[byte] >> offset) & 7; //Desplaza la ficha a la derecha y quedate solo con 3 bits

        return ficha; //Devolvemos el numero
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





void marcarPosicion(unsigned char* marcas, int indice){
    int byte = indice / 8;
    int bit = indice % 8;

    marcas[byte] |= (1 << bit);
}



bool estaMarcada(unsigned char* marcas, int indice){
    int byte = indice / 8;
    int bit = indice % 8;

    return (marcas[byte] & (1 << bit)) != 0;
}



void limpiarMarcas(unsigned char* marcas, int bytesMarcas){
    for (int i = 0; i < bytesMarcas; i++)
    {
        marcas[i] = 0;
    }
}





void redimensionarMarcas(unsigned char*& marcas, int posiciones, int& bytesMarcas){
    int nuevosBytes = (posiciones + 7) / 8;

    unsigned char* nuevasMarcas = new unsigned char[nuevosBytes];

    for (int i = 0; i < nuevosBytes; i++){
        nuevasMarcas[i] = 0;
    }


    delete[] marcas;
    marcas = nuevasMarcas;
    bytesMarcas = nuevosBytes;
}






