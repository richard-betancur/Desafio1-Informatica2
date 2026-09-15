#ifndef TABLERO_H
#define TABLERO_H

void crearTablero(unsigned char*& datos, int filas, int columnas);
void destruirTablero(unsigned char*& datos);
void mostrarTablero(unsigned char* datos, int filas, int columnas);
int obtenerFichaTablero(unsigned char* datos, int filas, int columnas, int fila, int columna);
void eliminarFicha(unsigned char* datos, int filas, int columnas, int fila, int columna);
void aplicarGravedad(unsigned char* datos, int filas, int columnas);
void rellenarVacios(unsigned char* datos, int filas, int columnas);

void agregarFila(unsigned char*& datos, int& filas, int columnas, int posicion);
void eliminarFila(unsigned char*& datos, int& filas, int columnas, int posicion);

#endif