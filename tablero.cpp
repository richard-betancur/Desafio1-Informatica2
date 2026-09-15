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

            if (ficha == 0)
            {
                cout << "A ";
            }
            else if (ficha == 1)
            {
                cout << "B ";
            }
            else if (ficha == 2)
            {
                cout << "C ";
            }
            else if (ficha == 3)
            {
                cout << "D ";
            }
            else if (ficha == 4)
            {
                cout << "E ";
            }
            else if (ficha == 5)
            {
                cout << "F ";
            }
        }

        cout << endl;
    }
}

void destruirTablero(unsigned char*& datos){

    delete[] datos;
    datos = nullptr;
}