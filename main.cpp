#include <iostream>
#include "bits.h"
#include "tablero.h"

using namespace std;

int main()
{
    unsigned char* datos = nullptr;

    int filas;
    int columnas;

    cout << "Por favor ingrese el numero de filas: ";
    cin >> filas;

    cout << "Por favor ingrese el numero de columnas: ";
    cin >> columnas;

    crearTablero(datos, filas, columnas);

    mostrarTablero(datos, filas, columnas);

    destruirTablero(datos);

    return 0;
}
