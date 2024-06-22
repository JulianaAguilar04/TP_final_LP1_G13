
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
