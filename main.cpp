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

    ponerFicha(datos, 0 * 3, 2);
    ponerFicha(datos, 5 * 3, 2);
    ponerFicha(datos, 10 * 3, 2);

    cout << endl;
    mostrarTablero(datos, filas, columnas);

    int bytesMarcas = (filas * columnas + 7) / 8;

    unsigned char* marcas = new unsigned char[bytesMarcas];

    for (int i = 0; i < bytesMarcas; i++){
        marcas[i] = 0;
    }

    detectarCombinaciones(datos, filas, columnas, marcas);
    eliminarMarcadas(datos, filas, columnas, marcas);

    cout << endl;
    mostrarTablero(datos, filas, columnas);

    cout << endl;

    for (int i = 0; i < filas * columnas; i++){
        cout << "Posicion " << i << ": " << estaMarcada(marcas, i) << endl;
    }

    delete[] marcas;

    destruirTablero(datos);

    return 0;
}
