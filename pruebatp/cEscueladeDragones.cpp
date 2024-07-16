#include "cEscueladeDragones.h"
using namespace std;

cEscueladeDragones::cEscueladeDragones(vector<cJinete*> Jinetes_isla, vector<cDragon*> Dragones_isla)
{
	this->Jinetes_isla = Jinetes_isla;
	this->Dragones_isla = Dragones_isla;
}

int cEscueladeDragones::mainE()
{
    int opcion;
    do {
        cout << "------ USTED ESTA EN LA ESCUELA DE LA ISLA ------" << endl;
        cout << "1) Estudio de dragones" << endl;
        cout << "2) Lista de dragones conocidos " << endl;
        cout << "3) Entrenar " << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;
        limpiarPantallaE();

        switch (opcion)
        {
        case 1:
            EstudioDeDragones(Dragones_isla);
            break;
        case 2:
            ListaDeDragones(Dragones_isla);
            break;
        case 3:
            EntrenarDragones(Jinetes_isla);
            break;

        case 4:
            cout << "Saliendo de la Escuela de Dragones..." << endl;
            break;

        default:
            cout << "Opcion invalida: Vuelva a intentarlo" << endl;
            break;
        }
        if (opcion != 4) {
            cout << "Presione Enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            limpiarPantallaE();
        }

    } while (opcion != 4);
   
    return 0;
}

void cEscueladeDragones::EstudioDeDragones(vector<cDragon*> &Dragones_isla)
{
    int clase = 0;
    cDragon* nuevoDragon = nullptr;

    cout << "Usted ha encontrado un nuevo dragon!" << endl;
    cout << "A que clase pertenece este nuevo dragon?" << endl;
    cout << "1) Fogonera" << endl;
    cout << "2) Embestida" << endl;
    cout << "3) Marejada" << endl;
    cin >> clase;

    try {
        if (clase != 1 && clase != 2 && clase != 3)
            throw "Ninguna opcion es válida";

        if (clase == 1) {
            nuevoDragon = cFogonera::AltaDragon();
        }
        else if (clase == 2) {
            nuevoDragon = cEmbestida::AltaDragon();
        }
        else if (clase == 3) {
            nuevoDragon = cMarejada::AltaDragon();
        }
        Dragones_isla.push_back(nuevoDragon);
        cout << "Dragon agregado exitosamente!" << endl;
    }
    catch (const char* s) {
        cout << "catch:" << s << endl;
    }
}

void cEscueladeDragones::ListaDeDragones(const vector<cDragon*>& Dragones_isla)
{
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (cDragon *dragon : Dragones_isla) {
        cout << (*dragon);
    }
}

void cEscueladeDragones::EntrenarDragones(vector<cJinete*>& Jinetes_isla)
{
    for (cJinete* jinete : Jinetes_isla) {
        //obtengo la lista de dragones del jinete
        vector<cDragon*> dragones = jinete->getMisDragones();
        for (cDragon* dragon : dragones) {
            //entreno cada dragon de la lista del jinete
            //verifico que clase de dragon es y llamo a su metodo de entrenar correspondiente
            if (cFogonera* fogonera = dynamic_cast<cFogonera*>(dragon)) {
                fogonera->Entrenar("Resistencia al calor", (*jinete));
                fogonera->Entrenar("Control de fuego", (*jinete));
                cout << endl;
            }
            else if (cEmbestida* embestida = dynamic_cast<cEmbestida*>(dragon)) {
                embestida->Entrenar("Obstaculos", (*jinete));
                embestida->Entrenar("Carrera de velocidad", (*jinete));
                embestida->Entrenar("Fuerza de impacto", (*jinete));
                cout << endl;
            }
            else if (cMarejada* marejada = dynamic_cast<cMarejada*>(dragon)) {
                marejada->Entrenar("Diferentes terrenos", (*jinete));
                cout << endl;
            }
        }
        cout << endl;
    }
}

cEscueladeDragones::~cEscueladeDragones()
{
}
