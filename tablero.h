#ifndef TABLERO_H
#define TABLERO_H

void crearTablero(unsigned char*& datos, int filas, int columnas);
void destruirTablero(unsigned char*& datos);
void mostrarTablero(unsigned char* datos, int filas, int columnas);

#endif