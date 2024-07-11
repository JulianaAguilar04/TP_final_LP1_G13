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

    } while (opcion != 4);
   
    return 0;
}

void cEscueladeDragones::MOSTRAR()
{
	cout << "HOLAAA" << endl;
}

void cEscueladeDragones::EstudioDeDragones(vector<cDragon*> &Dragones_isla)
{
    string nombre, caracteristica, tamano, color;
    int velocidad = 0, resistencia = 0, hab = 0;
    bool estado;
    char domado;
    vector<string> v_habilidades;

    cout << "Usted ha encontrado un nuevo dragon!" << endl;
    cout << "Ingrese el nombre del dragon: ";
    cin >> nombre;
    cout << "Ingrese las caracteristicas del dragon: ";
    cin >> caracteristica;
    cout << "Ingrese el tamano del dragon: ";
    cin >> tamano;
    cout << "Ingrese el color del dragon: ";
    cin >> color;
    cout << "El dragon esta domado? (s/n): ";
    cin >> domado;
    estado = (domado == 's' || domado == 'S');
    cout << "Ingrese la velocidad del dragon:" << endl;
    cin >> velocidad;
    cout << "Ingrese la resistencia del dragon:" << endl;
    cin >> resistencia;
    cout << "HABILIDADES" << endl;
    cout << "Cantidad de habilidades:" << endl;
    cin >> hab;

    v_habilidades.reserve(hab); //reservo espacio para la cantidades de habilidades
    for (int i = 0; i < hab; i++)
    {
        string habilidad;
        cout << "Ingrese habilidad:" << (i + 1) << ":" << endl;
        cin >> habilidad;
        v_habilidades.push_back(habilidad);
    }

    string tipoAtaque, danioAtaque, alcanceAtaque;
    cout << "Ingrese el tipo de ataque del dragón: ";
    cin >> tipoAtaque;
    cout << "Ingrese el daño del ataque del dragón: ";
    cin >> danioAtaque;
    cout << "Ingrese el alcance del ataque del dragón: ";
    cin >> alcanceAtaque;
    cAtaque* ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);

    // Crear el nuevo objeto cDragon y agregarlo al vector
    Dragones_isla.push_back(new cDragon(nombre, caracteristica, tamano, color, estado, /*velocidad, resistencia, */ v_habilidades, ataque));
    cout << "Dragon agregado exitosamente!" << endl;
}

void cEscueladeDragones::ListaDeDragones(const vector<cDragon*>& Dragones_isla)
{
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (const auto& dragon : Dragones_isla) {
        cout << dragon->to_string();
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
                fogonera->EntrenarFogonera("Resistencia al calor", (*jinete));
                fogonera->EntrenarFogonera("Control de fuego", (*jinete));
                cout << endl;
            }
            else if (cEmbestida* embestida = dynamic_cast<cEmbestida*>(dragon)) {
                embestida->EntrenarEmbestida("Obstaculos", (*jinete));
                embestida->EntrenarEmbestida("Carrera de velocidad", (*jinete));
                embestida->EntrenarEmbestida("Fuerza de impacto", (*jinete));
                cout << endl;
            }
            else if (cMarejada* marejada = dynamic_cast<cMarejada*>(dragon)) {
                marejada->EntrenarMarejada("Diferentes terrenos", (*jinete));
                cout << endl;
            }
        }
        cout << endl;
    }
}

cEscueladeDragones::~cEscueladeDragones()
{
}
