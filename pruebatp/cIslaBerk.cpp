#pragma once
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
    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Escuela de dragones" << endl;
        cout << "2) Batalla de dragones" << endl;
        cout << "3) Carrera de dragones" << endl;
        cout << "4) Lista de habitantes de la isla" << endl;
        cout << "5) Historial de logros de vikingos " << endl;
        cout << "6) Salir" << endl;
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
        cout << "                   \\=\\            ||    /"<< endl;
        cout << "                    \\=\\____       |\\    \\""" << endl;
        cout << "                   / \\/    `     <__)    \\""" << endl;
        cout << "                   | |                    |" << endl;
        cout << "                 ,__\\,\\                  ./" << endl;
        cout << "                '-__________>  \\.______/"<< endl;
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
            //ListaDePersonas(Jinetes_isla, Vikingos_isla);
            break;
        case 5:
            //MostrarDragonesMatados(Vikingos_isla);
        case 6:
            cout << "Muchas gracias por visitar la Isla de Berk" << endl;
            break;

        default:
            cout << "Opcion invalida: Intentelo de nuevo" << endl;
            break;
        }
        cout << endl;
        if (opcion != 6) {
            cout << "Presione Enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            limpiarPantalla();
        }

    } while (opcion != 6);

    return 0;
}
/*
void ListaDePersonas(vector<cJinete*>&Jinetes_isla, vector<cVikingo*>Vikingos_isla) {

    //imprimo todas las personas de la isla
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    }

}
*/


cIslaBerk::~cIslaBerk()
{
    delete Escuela;
    delete Batalla;
    delete Carrera;
}
