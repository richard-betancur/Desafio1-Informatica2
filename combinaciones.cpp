#include "combinaciones.h"
#include "bits.h"

int detectarCombinaciones(unsigned char* datos, int filas, int columnas,
                          unsigned char* marcas, int& cantidadCombinaciones)
{
    int cantidadMarcadas = 0;
    cantidadCombinaciones = 0;

    // COMBINACIONES HORIZONTALES

    for (int fila = 0; fila < filas; fila++)
    {
        int columna = 0;

        while (columna < columnas)
        {
            int indice = fila * columnas + columna;
            int ficha = obtenerFicha(datos, indice * 3);

            if (ficha == 6)
            {
                columna++;
            }
            else
            {
                int inicio = columna;
                int fin = columna;

                while (fin + 1 < columnas)
                {
                    int indiceSiguiente = fila * columnas + fin + 1;
                    int fichaSiguiente = obtenerFicha(datos, indiceSiguiente * 3);

                    if (fichaSiguiente == ficha)
                    {
                        fin++;
                    }
                    else
                    {
                        break;
                    }
                }

                int cantidad = fin - inicio + 1;

                if (cantidad >= 3)
                {
                    cantidadCombinaciones++;

                    for (int c = inicio; c <= fin; c++)
                    {
                        int indiceMarcado = fila * columnas + c;

                        if (!estaMarcada(marcas, indiceMarcado))
                        {
                            cantidadMarcadas++;
                            marcarPosicion(marcas, indiceMarcado);
                        }
                    }
                }

                columna = fin + 1;
            }
        }
    }


    // COMBINACIONES VERTICALES

    for (int columna = 0; columna < columnas; columna++)
    {
        int fila = 0;

        while (fila < filas)
        {
            int indice = fila * columnas + columna;
            int ficha = obtenerFicha(datos, indice * 3);

            if (ficha == 6)
            {
                fila++;
            }
            else
            {
                int inicio = fila;
                int fin = fila;

                while (fin + 1 < filas)
                {
                    int indiceSiguiente = (fin + 1) * columnas + columna;
                    int fichaSiguiente = obtenerFicha(datos, indiceSiguiente * 3);

                    if (fichaSiguiente == ficha)
                    {
                        fin++;
                    }
                    else
                    {
                        break;
                    }
                }

                int cantidad = fin - inicio + 1;

                if (cantidad >= 3)
                {
                    cantidadCombinaciones++;

                    for (int f = inicio; f <= fin; f++)
                    {
                        int indiceMarcado = f * columnas + columna;

                        if (!estaMarcada(marcas, indiceMarcado))
                        {
                            cantidadMarcadas++;
                            marcarPosicion(marcas, indiceMarcado);
                        }
                    }
                }

                fila = fin + 1;
            }
        }
    }

    return cantidadMarcadas;
}


void eliminarMarcadas(unsigned char* datos, int filas, int columnas,
                      unsigned char* marcas)
{
    for (int i = 0; i < filas * columnas; i++)
    {
        if (estaMarcada(marcas, i))
        {
            ponerFicha(datos, i * 3, 6);
        }
    }
}



