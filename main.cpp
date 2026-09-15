#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "combinaciones.h"

using namespace std;

int main()
{
    unsigned char* datos = nullptr;

    int filas;
    int columnas;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    crearTablero(datos, filas, columnas);

    // Creamos un espacio vacio en medio del tablero
    ponerFicha(datos, 5 * 3, 6);

    cout << endl;
    cout << "Tablero antes de la gravedad:" << endl;
    mostrarTablero(datos, filas, columnas);

    aplicarGravedad(datos, filas, columnas);

    cout << endl;
    cout << "Tablero despues de la gravedad:" << endl;
    mostrarTablero(datos, filas, columnas);

    rellenarVacios(datos, filas, columnas);

    cout << endl;
    cout << "Tablero despues de rellenar:" << endl;
    mostrarTablero(datos, filas, columnas);

    destruirTablero(datos);

    return 0;
}
