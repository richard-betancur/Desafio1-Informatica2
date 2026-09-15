#include <iostream>
#include "tablero.h"

using namespace std;

int main()
{
    unsigned char* datos = nullptr;

    int filas = 4;
    int columnas = 3;

    crearTablero(datos, filas, columnas);

    cout << "Tablero antes de eliminar la fila:" << endl;
    mostrarTablero(datos, filas, columnas);

    cout << endl;

    eliminarFila(datos, filas, columnas, 1);

    cout << "Tablero despues de eliminar la fila 1:" << endl;
    mostrarTablero(datos, filas, columnas);

    destruirTablero(datos);

    return 0;
}
