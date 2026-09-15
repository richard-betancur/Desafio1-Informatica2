#include <iostream>
#include "tablero.h"

using namespace std;

int main()
{
    unsigned char* datos = nullptr;

    int filas = 3;
    int columnas = 4;
    int capacidadBytes = 0;

    crearTablero(datos, filas, columnas, capacidadBytes);

    cout << "Antes:" << endl;
    mostrarTablero(datos, filas, columnas);

    cout << endl;

    eliminarColumna(datos, filas, columnas, 1, capacidadBytes);

    cout << "Despues de eliminar columna 1:" << endl;
    mostrarTablero(datos, filas, columnas);

    cout << endl;

    cout << "Filas: " << filas << endl;
    cout << "Columnas: " << columnas << endl;
    cout << "Capacidad: " << capacidadBytes << " bytes" << endl;

    destruirTablero(datos);

    return 0;
}