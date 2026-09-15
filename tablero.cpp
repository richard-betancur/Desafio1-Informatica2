#include "tablero.h"
#include "bits.h"
#include "iostream"

using namespace std;

void crearTablero(unsigned char*& datos, int filas, int columnas){
    int bitsNecesarios = filas * columnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    datos = new unsigned char[bytesNecesarios];

    for (int i = 0; i < bytesNecesarios; i++){
        datos[i] = 0;
    }

    for (int i = 0; i < filas * columnas; i++){
        int bitInicial = i * 3;
        int ficha = i % 6;

        ponerFicha(datos, bitInicial, ficha);
    }
}

void mostrarTablero(unsigned char* datos, int filas, int columnas)
{
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            int indice = fila * columnas + columna;
            int bitInicial = indice * 3;

            int ficha = obtenerFicha(datos, bitInicial);

            if (ficha == 0){
                cout << "A ";
            }
            else if (ficha == 1){
                cout << "B ";
            }
            else if (ficha == 2){
                cout << "C ";
            }
            else if (ficha == 3){
                cout << "D ";
            }
            else if (ficha == 4){
                cout << "E ";
            }
            else if (ficha == 5){
                cout << "F ";
            }
            else if (ficha == 6){
                cout << "_ ";
            }
        }

        cout << endl;
    }
}

int obtenerFichaTablero(unsigned char* datos, int filas, int columnas, int fila, int columna)
{
    int indice = fila * columnas + columna;
    int bitInicial = indice * 3;

    return obtenerFicha(datos, bitInicial);
}

void eliminarFicha(unsigned char* datos, int filas, int columnas, int fila, int columna)
{
    int indice = fila * columnas + columna;
    int bitInicial = indice * 3;

    ponerFicha(datos, bitInicial, 6);
}

void aplicarGravedad(unsigned char* datos, int filas, int columnas){
    for (int columna = 0; columna < columnas; columna++){
        int filaDestino = filas - 1;

        for (int filaBuscar = filas - 1; filaBuscar >= 0; filaBuscar--){
            int indiceBuscar = filaBuscar * columnas + columna;
            int ficha = obtenerFicha(datos, indiceBuscar * 3);

            if (ficha != 6){
                int indiceDestino = filaDestino * columnas + columna;

                ponerFicha(datos, indiceDestino * 3, ficha);

                filaDestino--;
            }
        }

        while (filaDestino >= 0){
            int indice = filaDestino * columnas + columna;

            ponerFicha(datos, indice * 3, 6);

            filaDestino--;
        }
    }
}

void rellenarVacios(unsigned char* datos, int filas, int columnas)
{
    for (int i = 0; i < filas * columnas; i++)
    {
        int ficha = obtenerFicha(datos, i * 3);

        if (ficha == 6)
        {
            int nuevaFicha = i % 6;

            ponerFicha(datos, i * 3, nuevaFicha);
        }
    }
}

void destruirTablero(unsigned char*& datos){

    delete[] datos;
    datos = nullptr;
}













