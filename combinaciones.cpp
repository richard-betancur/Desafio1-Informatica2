#include "combinaciones.h"
#include "bits.h"

int detectarCombinaciones(unsigned char* datos, int filas, int columnas, unsigned char* marcas)
{
    int cantidadMarcadas = 0;

    // COMBINACIONES HORIZONTALES
    for (int fila = 0; fila < filas; fila++){
        for (int columna = 0; columna < columnas - 2; columna++){
            int indice1 = fila * columnas + columna;
            int indice2 = fila * columnas + columna + 1;
            int indice3 = fila * columnas + columna + 2;

            int ficha1 = obtenerFicha(datos, indice1 * 3);
            int ficha2 = obtenerFicha(datos, indice2 * 3);
            int ficha3 = obtenerFicha(datos, indice3 * 3);

            if (ficha1 != 6 && ficha1 == ficha2 && ficha2 == ficha3){
                if (!estaMarcada(marcas, indice1)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice1);
                }

                if (!estaMarcada(marcas, indice2)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice2);
                }

                if (!estaMarcada(marcas, indice3)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice3);
                }
            }
        }
    }


    // COMBINACIONES VERTICALES
    for (int columna = 0; columna < columnas; columna++){
        for (int fila = 0; fila < filas - 2; fila++){
            int indice1 = fila * columnas + columna;
            int indice2 = (fila + 1) * columnas + columna;
            int indice3 = (fila + 2) * columnas + columna;

            int ficha1 = obtenerFicha(datos, indice1 * 3);
            int ficha2 = obtenerFicha(datos, indice2 * 3);
            int ficha3 = obtenerFicha(datos, indice3 * 3);

            if (ficha1 != 6 && ficha1 == ficha2 && ficha2 == ficha3){
                if (!estaMarcada(marcas, indice1)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice1);
                }

                if (!estaMarcada(marcas, indice2)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice2);
                }

                if (!estaMarcada(marcas, indice3)){
                    cantidadMarcadas++;
                    marcarPosicion(marcas, indice3);
                }
            }
        }
    }

    return cantidadMarcadas;
}


void eliminarMarcadas(unsigned char* datos, int filas, int columnas, unsigned char* marcas){
    for (int i = 0; i < filas * columnas; i++){
        if (estaMarcada(marcas, i)){
            ponerFicha(datos, i * 3, 6);
        }
    }
}



