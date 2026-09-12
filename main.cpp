#include <iostream>
#include "bits.h"

using namespace std;

int main()
{
    unsigned char datos[2];

    datos[0] = 0b01000000;
    datos[1] = 0b00000000;

    cout << obtenerFicha(datos, 6) << endl;

    return 0;
}
