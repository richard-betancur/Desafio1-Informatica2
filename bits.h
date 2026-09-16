/// ARCHIVO DE ENCABEZADO DEL MODULO DE BITS

#ifndef BITS_H
#define BITS_H


/// Existen funciones llamada... que resive estos datos y devuelve un... void no devuelve nada.

int obtenerFicha(unsigned char* datos, int bitInicial);  /// unsigned char* datos es un puntero a la memoria donde tenemos guardado el tablero
void ponerFicha(unsigned char* datos, int bitInicial, int ficha);

void marcarPosicion(unsigned char* marcas, int indice);
bool estaMarcada(unsigned char* marcas, int indice);

void limpiarMarcas(unsigned char* marcas, int bytesMarcas);

void redimensionarMarcas(unsigned char*& marcas, int posiciones, int& bytesMarcas);

#endif

/// Implementacion real en bits.cpp