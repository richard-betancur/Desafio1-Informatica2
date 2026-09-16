#ifndef JUEGO_H
#define JUEGO_H

void eliminarFichaJugador(unsigned char* datos, int filas, int columnas, int fila, int columna);

int procesarCascadas(unsigned char* datos, int filas, int columnas,
                     unsigned char* marcas, int bytesMarcas,
                     int& cantidadCombinaciones,
                     int& cantidadFichasEliminadas);

#endif