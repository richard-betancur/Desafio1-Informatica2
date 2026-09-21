#include "juego.h"
#include "combinaciones.h"
#include "tablero.h"
#include "bits.h"

void eliminarFichaJugador(unsigned char* datos, int filas, int columnas,int fila, int columna){
    eliminarFicha(datos, filas, columnas, fila, columna);
}


int procesarCascadas(unsigned char* datos, int filas, int columnas,
                     unsigned char* marcas, int bytesMarcas,
                     int& cantidadCombinaciones,
                     int& cantidadFichasEliminadas){

    int cantidadCascadas = 0;

    cantidadCombinaciones = 0;
    cantidadFichasEliminadas = 0;

    // La ficha eliminada por el jugador ya dejó un vacío.
    // Primero hacemos caer las fichas y rellenamos.
    aplicarGravedad(datos, filas, columnas);
    rellenarVacios(datos, filas, columnas);
    limpiarMarcas(marcas, bytesMarcas);

    int combinacionesEncontradas = 0;
    int cantidad = detectarCombinaciones(datos, filas, columnas, marcas, combinacionesEncontradas);

    while (cantidad > 0){
        // Esta combinación ES una cascada
        cantidadCascadas++;

        cantidadFichasEliminadas += cantidad;
        cantidadCombinaciones += combinacionesEncontradas;

        eliminarMarcadas(datos, filas, columnas, marcas);// Eliminamos las combinaciones encontradas
        aplicarGravedad(datos, filas, columnas);// Las fichas caen
        rellenarVacios(datos, filas, columnas);// Se generan fichas nuevas
        limpiarMarcas(marcas, bytesMarcas);// Preparamos la siguiente búsqueda

        combinacionesEncontradas = 0;
        // Buscamos si la nueva caída produjo otra combinación
        cantidad = detectarCombinaciones(datos, filas, columnas, marcas, combinacionesEncontradas);
    }

    return cantidadCascadas;
}




/*
int procesarCascadas(unsigned char* datos, int filas, int columnas,
                     unsigned char* marcas, int bytesMarcas,
                     int& cantidadCombinaciones,
                     int& cantidadFichasEliminadas){

    int cantidadCascadas = 0;

    cantidadCombinaciones = 0;
    cantidadFichasEliminadas = 0;

    // Primero reorganizamos el tablero después de la eliminación
    aplicarGravedad(datos,filas,columnas);
    rellenarVacios(datos,filas,columnas);
    limpiarMarcas(marcas,bytesMarcas);

    int combinacionesEncontradas = 0;
    int cantidad = detectarCombinaciones(datos,filas,columnas,marcas,combinacionesEncontradas);

    cantidadCombinaciones += combinacionesEncontradas;

    while (cantidad > 0){

        cantidadFichasEliminadas += cantidad;

        eliminarMarcadas(datos,filas,columnas,marcas);
        aplicarGravedad(datos,filas,columnas);
        rellenarVacios(datos,filas,columnas);
        limpiarMarcas(marcas,bytesMarcas);

        combinacionesEncontradas = 0;

        cantidad = detectarCombinaciones(datos,filas,columnas,marcas,combinacionesEncontradas);

        if (cantidad > 0){
            cantidadCascadas++;
        }

        cantidadCombinaciones += combinacionesEncontradas;
    }

    return cantidadCascadas;
}
*/