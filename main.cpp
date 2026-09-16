#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "combinaciones.h"
#include "juego.h"

using namespace std;

int main()
{
    unsigned char* datos = nullptr;

    int filas;
    int columnas;

    int fila;
    int columna;

    int eliminacionesJugador = 0;
    int capacidadBytes;

    int totalFichasEliminadas = 0;
    int totalCombinaciones = 0;
    int totalCascadas = 0;
    int puntaje = 0;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    while (cin.fail() || filas <= 0){
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Filas invalidas. Ingrese un numero mayor que 0: ";
        cin >> filas;
    }

    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    while (cin.fail() || columnas <= 0){
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Columnas invalidas. Ingrese un numero mayor que 0: ";
        cin >> columnas;
    }


    crearTablero(datos, filas, columnas, capacidadBytes);

    int totalPosiciones = filas * columnas;
    int bytesMarcas = (totalPosiciones + 7) / 8;
    unsigned char* marcas = new unsigned char[bytesMarcas];


    limpiarMarcas(marcas, bytesMarcas);

    cout << endl;
    cout << "Tablero inicial:" << endl;

    mostrarTablero(datos, filas, columnas);

    cout << endl;

    int opcion = -1;

    while (opcion != 0){
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1 Eliminar ficha" << endl;
        cout << "2 Agregar fila" << endl;
        cout << "3 Eliminar fila" << endl;
        cout << "4 Agregar columna" << endl;
        cout << "5 Eliminar columna" << endl;
        cout << "6 Mostrar estadisticas" << endl;
        cout << "0 Salir" << endl;

        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Entrada invalida. Ingrese un numero: ";
            cin >> opcion;
        }


        // OPCION 1: ELIMINAR FICHA
        if (opcion == 1){
            cout << endl;
            cout << "Ingrese la fila que desea eliminar: ";
            cin >> fila;

            while (cin.fail() || fila < 0 || fila >= filas){
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Fila invalida. Ingrese una fila entre 0 y " << filas - 1 << ": ";
                cin >> fila;
            }

            cout << "Ingrese la columna que desea eliminar: ";
            cin >> columna;

            while (cin.fail() || columna < 0 || columna >= columnas){
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Columna invalida. Ingrese una columna entre 0 y " << columnas - 1 << ": ";
                cin >> columna;
            }

            eliminarFichaJugador(datos, filas, columnas, fila, columna);

            eliminacionesJugador++;

            int cantidadCombinaciones;
            int cantidadFichasEliminadas;

            int cantidadCascadas = procesarCascadas(datos, filas, columnas, marcas, bytesMarcas, cantidadCombinaciones, cantidadFichasEliminadas);


            totalFichasEliminadas += cantidadFichasEliminadas;
            totalCombinaciones += cantidadCombinaciones;
            totalCascadas += cantidadCascadas;
            puntaje += cantidadFichasEliminadas * 10;
            puntaje += cantidadCascadas * 20;

            cout << endl;
            cout << "Tablero despues de procesar:" << endl;

            mostrarTablero(datos, filas, columnas);

            cout << endl;

            cout << "Cascadas: " << cantidadCascadas << endl;
            cout << "Combinaciones: " << cantidadCombinaciones << endl;
            cout << "Fichas eliminadas: " << cantidadFichasEliminadas << endl;
            cout << "Eliminaciones del jugador: " << eliminacionesJugador << endl;
        }


        // OPCION 2: AGREGAR FILA
        else if (opcion == 2){
            int posicion;

            cout << endl;
            cout << "Ingrese la posicion donde desea agregar la fila: ";
            cin >> posicion;

            while (cin.fail() || posicion < 0 || posicion > filas){
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Posicion invalida. Ingrese una posicion entre 0 y " << filas << ": ";
                cin >> posicion;
            }

            agregarFila(datos, filas, columnas, posicion, capacidadBytes);

            int totalPosiciones = filas * columnas;

            redimensionarMarcas(marcas, totalPosiciones, bytesMarcas);

            int cantidadCombinaciones;
            int cantidadFichasEliminadas;

            int cantidadCascadas = procesarCascadas(datos, filas, columnas, marcas, bytesMarcas, cantidadCombinaciones, cantidadFichasEliminadas);


            totalFichasEliminadas += cantidadFichasEliminadas;
            totalCombinaciones += cantidadCombinaciones;
            totalCascadas += cantidadCascadas;
            puntaje += cantidadFichasEliminadas * 10;
            puntaje += cantidadCascadas * 20;

            cout << endl;
            cout << "Fila agregada correctamente." << endl;

            if (cantidadCascadas > 0){
                cout << "Se produjeron " << cantidadCascadas << " cascada(s)." << endl;
            }

            cout << endl;
            cout << "Tablero actual:" << endl;

            mostrarTablero(datos, filas, columnas);
        }


        // OPCION 3: ELIMINAR FILA
        else if (opcion == 3){
            int posicion;

            if (filas <= 1){
                cout << endl;
                cout << "No se puede eliminar la fila." << endl;
            }
            else{
                cout << endl;
                cout << "Ingrese la posicion de la fila que desea eliminar: ";
                cin >> posicion;

                while (cin.fail() || posicion < 0 || posicion >= filas){
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "Posicion invalida. Ingrese una posicion entre 0 y " << filas - 1 << ": ";
                    cin >> posicion;
                }

                eliminarFila(datos, filas, columnas, posicion, capacidadBytes);

                int totalPosiciones = filas * columnas;

                redimensionarMarcas(marcas, totalPosiciones, bytesMarcas);

                int cantidadCombinaciones;
                int cantidadFichasEliminadas;

                int cantidadCascadas = procesarCascadas(datos, filas, columnas, marcas, bytesMarcas, cantidadCombinaciones, cantidadFichasEliminadas);


                totalFichasEliminadas += cantidadFichasEliminadas;
                totalCombinaciones += cantidadCombinaciones;
                totalCascadas += cantidadCascadas;
                puntaje += cantidadFichasEliminadas * 10;
                puntaje += cantidadCascadas * 20;

                cout << endl;
                cout << "Fila eliminada correctamente." << endl;

                if (cantidadCascadas > 0){
                    cout << "Se produjeron " << cantidadCascadas << " cascada(s)." << endl;
                }

                cout << endl;
                cout << "Tablero actual:" << endl;

                mostrarTablero(datos, filas, columnas);
            }
        }


        // OPCION 4: AGREGAR COLUMNA
        else if (opcion == 4){
            int posicion;

            cout << endl;
            cout << "Ingrese la posicion donde desea agregar la columna: ";
            cin >> posicion;

            while (cin.fail() || posicion < 0 || posicion > columnas){
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Posicion invalida. Ingrese una posicion entre 0 y " << columnas << ": ";
                cin >> posicion;
            }

            agregarColumna(datos, filas, columnas, posicion, capacidadBytes);

            int totalPosiciones = filas * columnas;

            redimensionarMarcas(marcas, totalPosiciones, bytesMarcas);

            int cantidadCombinaciones;
            int cantidadFichasEliminadas;

            int cantidadCascadas = procesarCascadas(datos, filas, columnas, marcas, bytesMarcas, cantidadCombinaciones, cantidadFichasEliminadas);

            totalFichasEliminadas += cantidadFichasEliminadas;
            totalCombinaciones += cantidadCombinaciones;
            totalCascadas += cantidadCascadas;
            puntaje += cantidadFichasEliminadas * 10;
            puntaje += cantidadCascadas * 20;

            cout << endl;
            cout << "Columna agregada correctamente." << endl;

            if (cantidadCascadas > 0){
                cout << "Se produjeron " << cantidadCascadas << " cascada(s)." << endl;
            }

            cout << endl;
            cout << "Tablero actual:" << endl;

            mostrarTablero(datos, filas, columnas);
        }



        // OPCION 5: ELIMINAR COLUMNA
        else if (opcion == 5){
            int posicion;

            if (columnas <= 1){
                cout << endl;
                cout << "No se puede eliminar la columna." << endl;
            }
            else{
                cout << endl;
                cout << "Ingrese la posicion de la columna que desea eliminar: ";
                cin >> posicion;

                while (cin.fail() || posicion < 0 || posicion >= columnas){
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "Posicion invalida. Ingrese una posicion entre 0 y " << columnas - 1 << ": ";
                    cin >> posicion;
                }

                eliminarColumna(datos, filas, columnas, posicion, capacidadBytes);

                int totalPosiciones = filas * columnas;

                redimensionarMarcas(marcas, totalPosiciones, bytesMarcas);

                int cantidadCombinaciones;
                int cantidadFichasEliminadas;

                int cantidadCascadas = procesarCascadas(datos, filas, columnas, marcas, bytesMarcas, cantidadCombinaciones, cantidadFichasEliminadas);

                totalFichasEliminadas += cantidadFichasEliminadas;
                totalCombinaciones += cantidadCombinaciones;
                totalCascadas += cantidadCascadas;
                puntaje += cantidadFichasEliminadas * 10;
                puntaje += cantidadCascadas * 20;

                cout << endl;
                cout << "Columna eliminada correctamente." << endl;

                if (cantidadCascadas > 0){
                    cout << "Se produjeron " << cantidadCascadas << " cascada(s)." << endl;
                }

                cout << endl;
                cout << "Tablero actual:" << endl;

                mostrarTablero(datos, filas, columnas);
            }
        }



        // OPCION 6: ESTADISTICAS
        else if (opcion == 6){
            cout << endl;
            cout << "========== ESTADISTICAS ==========" << endl;

            cout << "Filas actuales: " << filas << endl;
            cout << "Columnas actuales: " << columnas << endl;
            cout << "Eliminaciones del jugador: " << eliminacionesJugador << endl;
            cout << "Fichas eliminadas: " << totalFichasEliminadas << endl;
            cout << "Combinaciones detectadas: " << totalCombinaciones << endl;
            cout << "Cascadas producidas: " << totalCascadas << endl;
            cout << "Puntaje: " << puntaje << endl;
        }



        // SALIR
        else if (opcion == 0){
            cout << "Saliendo del juego..." << endl;
        }



        // OPCION INVALIDA
        else{
            cout << "Opcion invalida." << endl;
        }
    }


    destruirTablero(datos);
    delete[] marcas;
    return 0;
}