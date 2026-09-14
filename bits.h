#ifndef BITS_H   /// se usa para que BITS_H no se incluya varias veces accidentalmente
#define BITS_H   /// se usa para que BITS_H no se incluya varias veces accidentalmente


///Declaramos una Funcion obtenerFicha que resivira datos y bitInicial y devolvera un entero
int obtenerFicha(unsigned char* datos, int bitInicial); ///unsigned char* es un puntero a nuestra memoria dinamica
void ponerFicha(unsigned char* datos, int bitInicial, int ficha);

#endif

/// * es una direccion que apunta a una zona de memoria donde tenemos bytes