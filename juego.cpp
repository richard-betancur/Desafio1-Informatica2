#include "juego.h"
#include "combinaciones.h"
#include "tablero.h"
#include "bits.h"

int procesarCascadas(unsigned char* datos, int filas, int columnas,
                     unsigned char* marcas, int bytesMarcas)
{
    int cantidadCascadas = 0;
    int cantidadCombinaciones = 0;

    int cantidad = detectarCombinaciones(
        datos,
        filas,
        columnas,
        marcas,
        cantidadCombinaciones
        );

    while (cantidad > 0)
    {
        cantidadCascadas++;

        eliminarMarcadas(datos, filas, columnas, marcas);

        aplicarGravedad(datos, filas, columnas);

        rellenarVacios(datos, filas, columnas);

        limpiarMarcas(marcas, bytesMarcas);

        cantidad = detectarCombinaciones(
            datos,
            filas,
            columnas,
            marcas,
            cantidadCombinaciones
            );
    }

    return cantidadCascadas;
}