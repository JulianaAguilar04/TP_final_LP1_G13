
/* #include "EscueladeDragones.h"
#include "cDragon.h"
#include <iostream>
using namespace std; */
/*
void EscueladeDragones(vector<cDragon*>& Dragones_isla) {
    int opcion;
    do {
        cout << "\nUSTED ESTA EN LA ESCUELA DE LA ISLA" << endl;
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
            EntrenarDragones(Dragones_isla);
            break;

        case 4:
            cout << "Saliendo de la Escuela de Dragones..." << endl;
            break;

        default:
            cout << "Opcion invalida: Vuelva a intentarlo" << endl;
            break;
        }

    } while (opcion != 4);
}

void EstudioDeDragones(vector<cDragon*>& Dragones_isla) {
    string nombre, caracteristica, tamano, color;
    bool estado;
    char domado;
    cout << "Ingrese el nombre del dragon: ";
    cin >> nombre;
    cout << "Ingrese las caracteristicas del dragon: ";
    cin >> caracteristica;
    cout << "Ingrese el tamano del dragon: ";
    cin >> tamano;
    cout << "Ingrese el color del dragon: ";
    cin >> color;
    cout << "¿El dragon esta domado? (s/n): ";
    cin >> domado;
    estado = (domado == 's' || domado == 'S');

    cAtaque* ataque = nullptr;  // Inicialmente sin ataque asignado
    Dragones_isla.push_back(new cDragon(nombre, caracteristica, tamano, color, estado, ataque));

    cout << "Dragon agregado exitosamente!" << endl;
}

void ListaDeDragones(const vector<cDragon*>& Dragones_isla) {
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (const auto& dragon : Dragones_isla) {
        cout << dragon->to_string() << endl;
    }
}

void EntrenarDragones(vector<cDragon*>& Dragones_isla) {
    for (auto& dragon : Dragones_isla) {
        if (dragon->getEstado()) {
            dragon->Entrenar();
            cout << "El dragon " << dragon->getNombre() << " ha sido entrenado." << endl;
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " no esta domado y no puede ser entrenado." << endl;
        }
    }
}


/*LO QUE ESTABA ANTES: 
#include "EscueladeDragones.h"


void EscueladeDragones(&Dragones_isla)
{
		int opcion;

		do {
			cout << "1) Estudio de dragones" << endl;
			cout << "2) Lista de dragones conocidos " << endl;
			cout << "3) Entrenar " << endl;
			cout << "4) Salir" << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				break;

			case 2:
				break;

			default:
				cout << "Error" << endl;
				break;

			}

		} while (opcion != 4);


}
*/

#include "EscueladeDragones.h"

EscueladeDragones::EscueladeDragones(string Nombre) {
    this->Nombre = Nombre;
}

void EscueladeDragones::AgregarJinete(cJinete* Jinete) {
    Alumnos.push_back(Jinete);
}

void EscueladeDragones::AgregarDragon(cDragon* Dragon) {
    Dragones.push_back(Dragon);
}

void EscueladeDragones::ImprimirEstado() {
    cout << "Escuela de Dragones: " << Nombre << endl;
    cout << "Lista de Alumnos:" << endl;
    for (auto alumno : Alumnos) {
        cout << alumno->to_string() << endl;
    }
    cout << "Lista de Dragones:" << endl;
    for (auto dragon : Dragones) {
        cout << dragon->getNombre() << " - " << dragon->getColor() << " - " << dragon->getTamano() << endl;
    }
}
