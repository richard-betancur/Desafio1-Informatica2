#include <iostream>
#include "bits.h"

using namespace std;

int main()
{
    unsigned char datos[3] = {0, 0, 0};

    ponerFicha(datos, 0, 5);
    ponerFicha(datos, 3, 2);
    ponerFicha(datos, 6, 7);
    ponerFicha(datos, 9, 4);

    cout << "Ficha en bit 0: " << obtenerFicha(datos, 0) << endl;
    cout << "Ficha en bit 3: " << obtenerFicha(datos, 3) << endl;
    cout << "Ficha en bit 6: " << obtenerFicha(datos, 6) << endl;
    cout << "Ficha en bit 9: " << obtenerFicha(datos, 9) << endl;


    return 0;
}
