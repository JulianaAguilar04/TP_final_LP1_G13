#include "cIslaBerk.h"


cIslaBerk::cIslaBerk(vector<cJinete*> Jinetes_isla, vector<cDragon*> Dragones_isla, vector<cVikingo*> Vikingos_isla)
{
    Escuela = new cEscueladeDragones(Jinetes_isla, Dragones_isla);
    Batalla = new cBatalladeDragones(Vikingos_isla, Dragones_isla);
}

int cIslaBerk::mainBerk()
{
    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Escuela de dragones" << endl;
        cout << "2) Batalla de dragones" << endl;
        cout << "3) Lista de habitantes de la isla" << endl;
        cout << "4) Historial de logros de vikingos " << endl;
        cout << "5) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Escuela->mainE();
            break;
        case 2:
            Batalla->mainB();
            break;
        case 3:
            //ListaDePersonas(Personas_isla);
            break;
        case 4:
            //MostrarDragonesMatados(Vikingos_isla);
        case 5:
            cout << "Muchas gracias por visitar la Isla de Berk" << endl;
            break;

        default:
            cout << "Opcion invalida: Intentelo de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (opcion != 5);

    return 0;
}

cIslaBerk::~cIslaBerk()
{
    delete Escuela;
    delete Batalla;
}
