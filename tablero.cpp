#include "tablero.h"

void crearTablero(unsigned char*& datos, int filas, int columnas){
    int bitsNecesarios = filas * columnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    datos = new unsigned char[bytesNecesarios];
}

void destruirTablero(unsigned char*& datos){

    delete[] datos;
    datos = nullptr;
}