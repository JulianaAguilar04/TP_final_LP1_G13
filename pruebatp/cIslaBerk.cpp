#pragma once
#include <stdexcept> 
#include "cIslaBerk.h"
#include "cCarreradeDragones.h"

cIslaBerk::cIslaBerk(vector<cJinete*> Jinetes_isla, vector<cDragon*> Dragones_isla, vector<cVikingo*> Vikingos_isla)
{
    Escuela = new cEscueladeDragones(Jinetes_isla, Dragones_isla);
    Batalla = new cBatalladeDragones(Vikingos_isla, Dragones_isla);
    Carrera = new cCarreradeDragones(Jinetes_isla);
}

int cIslaBerk::mainBerk()
{
    try {
        int opcion;
        do {
            cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
            cout << "1) Escuela de dragones" << endl;
            cout << "2) Batalla de dragones" << endl;
            cout << "3) Carrera de dragones" << endl;
            cout << "4) Salir" << endl;
            cout << "" << endl;
            cout << "                  __/>^^^;:," << endl;
            cout << "     __  __      /-.       :,/|/|" << endl;
            cout << "    /  \\/  \\  __/ ^         :,/ \\__" << endl;
            cout << "   |   \\/   |(~             ;/ /  /" << endl;
            cout << "   \\       {  `-'--._       / / ,<  " << endl;
            cout << "    \\      /,__.   /=\     /  _/  >|_'." << endl;
            cout << "     \\    /  `_ `--------'    __ / ',\ \\""" << endl;
            cout << "      \\  / ,_// ,---_____,   ,_  \_  ,| |" << endl;
            cout << "       \\/   `--' |=|           \._/ ,/  |" << endl;
            cout << "                  \\=\\            `,,/   |" << endl;
            cout << "                   \\=\\            ||    /" << endl;
            cout << "                    \\=\\____       |\\    \\""" << endl;
            cout << "                   / \\/    `     <__)    \\""" << endl;
            cout << "                   | |                    |" << endl;
            cout << "                 ,__\\,\\                  ./" << endl;
            cout << "                '-__________>  \\.______/" << endl;
            cout << "" << endl;

            cin >> opcion;
            limpiarPantalla();

            switch (opcion)
            {
            case 1:
                Escuela->mainE();
                break;
            case 2:
                Batalla->mainB();
                break;
            case 3:
            {
                Carrera->mainC();
                break;
            }
            case 4:
                cout << "Muchas gracias por visitar la Isla de Berk" << endl;
                break;

            default:
                cout << "Opcion invalida: Intentelo de nuevo" << endl;
                break;
            }
            cout << endl;
            if (opcion != 4) {
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
                limpiarPantalla();
            }

        } while (opcion != 4);
    }
    catch (const exception& e) {
        cout << "Error en la ejercucion del programa: " << e.what() << endl;
    }
    // Eliminar dragones de Dragones_isla solo si no se han movido a otra parte
    for (cDragon* dragon : Dragones_isla) {
        if (dragon != nullptr) {
            delete dragon;
        }
    }
    Dragones_isla.clear();

    // Eliminar jinetes de Jinetes_isla
    for (cJinete* jinete : Jinetes_isla) {
        if (jinete != nullptr) {
            delete jinete;
        }
    }
    Jinetes_isla.clear();

    // Eliminar vikingos de Vikingos_isla
    for (cVikingo* vikingo : Vikingos_isla) {
        if (vikingo != nullptr) {
            delete vikingo;
        }
    }
    Vikingos_isla.clear();

    return 0;
}

cIslaBerk::~cIslaBerk()
{
    delete Escuela;
    delete Batalla;
    delete Carrera;
}
