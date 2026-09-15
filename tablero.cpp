#include "tablero.h"
#include "bits.h"
#include "iostream"

using namespace std;

void crearTablero(unsigned char*& datos, int filas, int columnas, int& capacidadBytes){
    int bitsNecesarios = filas * columnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    capacidadBytes = bytesNecesarios;

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

void mostrarTablero(unsigned char* datos, int filas, int columnas){
    for (int fila = 0; fila < filas; fila++){
        for (int columna = 0; columna < columnas; columna++){
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

int obtenerFichaTablero(unsigned char* datos, int filas, int columnas, int fila, int columna){
    int indice = fila * columnas + columna;
    int bitInicial = indice * 3;

    return obtenerFicha(datos, bitInicial);
}

void eliminarFicha(unsigned char* datos, int filas, int columnas, int fila, int columna){
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

void rellenarVacios(unsigned char* datos, int filas, int columnas){
    for (int i = 0; i < filas * columnas; i++){
        int ficha = obtenerFicha(datos, i * 3);

        if (ficha == 6){
            int nuevaFicha = i % 6;

            ponerFicha(datos, i * 3, nuevaFicha);
        }
    }
}

void agregarFila(unsigned char*& datos, int& filas, int columnas, int posicion, int& capacidadBytes){
    int nuevasFilas = filas + 1;

    int bitsNecesarios = nuevasFilas * columnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    unsigned char* nuevosDatos = new unsigned char[bytesNecesarios];

    for (int i = 0; i < bytesNecesarios; i++){
        nuevosDatos[i] = 0;
    }

    for (int fila = 0; fila < nuevasFilas; fila++){
        if (fila == posicion){
            for (int columna = 0; columna < columnas; columna++){
                int indiceNuevo = fila * columnas + columna;
                int fichaNueva = indiceNuevo % 6;

                ponerFicha(nuevosDatos, indiceNuevo * 3, fichaNueva);
            }
        }
        else{
            int filaVieja;

            if (fila < posicion){
                filaVieja = fila;
            }
            else{
                filaVieja = fila - 1;
            }

            for (int columna = 0; columna < columnas; columna++){
                int indiceViejo = filaVieja * columnas + columna;
                int ficha = obtenerFicha(datos, indiceViejo * 3);

                int indiceNuevo = fila * columnas + columna;

                ponerFicha(nuevosDatos, indiceNuevo * 3, ficha);
            }
        }
    }

    delete[] datos;

    datos = nuevosDatos;

    filas = nuevasFilas;

    capacidadBytes = bytesNecesarios;
}

void eliminarFila(unsigned char*& datos, int& filas, int columnas, int posicion, int& capacidadBytes){
    int nuevasFilas = filas - 1;

    int bitsNecesarios = nuevasFilas * columnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    double ocupacion = (double)bytesNecesarios / capacidadBytes;

    int bytesReservados;

    if (ocupacion < 0.65){
        bytesReservados = bytesNecesarios;
    }
    else{
        bytesReservados = capacidadBytes;
    }

    unsigned char* nuevosDatos = new unsigned char[bytesReservados];

    for (int i = 0; i < bytesReservados; i++){
        nuevosDatos[i] = 0;
    }

    int filaNueva = 0;

    for (int filaVieja = 0; filaVieja < filas; filaVieja++){
        if (filaVieja != posicion){
            for (int columna = 0; columna < columnas; columna++){
                int indiceViejo = filaVieja * columnas + columna;

                int ficha = obtenerFicha(datos, indiceViejo * 3);

                int indiceNuevo = filaNueva * columnas + columna;

                ponerFicha(nuevosDatos, indiceNuevo * 3, ficha);
            }

            filaNueva++;
        }
    }

    delete[] datos;

    datos = nuevosDatos;

    filas = nuevasFilas;

    capacidadBytes = bytesReservados;
}

void agregarColumna(unsigned char*& datos, int filas, int& columnas,
                    int posicion, int& capacidadBytes)
{
    int nuevasColumnas = columnas + 1;

    int bitsNecesarios = filas * nuevasColumnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    unsigned char* nuevosDatos = new unsigned char[bytesNecesarios];

    for (int i = 0; i < bytesNecesarios; i++)
    {
        nuevosDatos[i] = 0;
    }

    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < nuevasColumnas; columna++)
        {
            int indiceNuevo = fila * nuevasColumnas + columna;

            if (columna == posicion)
            {
                int fichaNueva = indiceNuevo % 6;

                ponerFicha(nuevosDatos, indiceNuevo * 3, fichaNueva);
            }
            else
            {
                int columnaVieja;

                if (columna < posicion)
                {
                    columnaVieja = columna;
                }
                else
                {
                    columnaVieja = columna - 1;
                }

                int indiceViejo = fila * columnas + columnaVieja;

                int ficha = obtenerFicha(datos, indiceViejo * 3);

                ponerFicha(nuevosDatos, indiceNuevo * 3, ficha);
            }
        }
    }

    delete[] datos;

    datos = nuevosDatos;

    columnas = nuevasColumnas;

    capacidadBytes = bytesNecesarios;
}

void eliminarColumna(unsigned char*& datos, int filas, int& columnas,
                     int posicion, int& capacidadBytes)
{
    int nuevasColumnas = columnas - 1;

    int bitsNecesarios = filas * nuevasColumnas * 3;
    int bytesNecesarios = (bitsNecesarios + 7) / 8;

    double ocupacion = (double)bytesNecesarios / capacidadBytes;

    int bytesReservados;

    if (ocupacion < 0.65)
    {
        bytesReservados = bytesNecesarios;
    }
    else
    {
        bytesReservados = capacidadBytes;
    }

    unsigned char* nuevosDatos = new unsigned char[bytesReservados];

    for (int i = 0; i < bytesReservados; i++)
    {
        nuevosDatos[i] = 0;
    }

    for (int fila = 0; fila < filas; fila++)
    {
        int columnaNueva = 0;

        for (int columnaVieja = 0; columnaVieja < columnas; columnaVieja++)
        {
            if (columnaVieja != posicion)
            {
                int indiceViejo = fila * columnas + columnaVieja;

                int ficha = obtenerFicha(datos, indiceViejo * 3);

                int indiceNuevo = fila * nuevasColumnas + columnaNueva;

                ponerFicha(nuevosDatos, indiceNuevo * 3, ficha);

                columnaNueva++;
            }
        }
    }

    delete[] datos;

    datos = nuevosDatos;

    columnas = nuevasColumnas;

    capacidadBytes = bytesReservados;
}

void destruirTablero(unsigned char*& datos){

    delete[] datos;
    datos = nullptr;
}













