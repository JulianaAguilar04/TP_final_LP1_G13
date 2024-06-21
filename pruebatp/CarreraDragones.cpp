#include "CarreradeDragones.h"

CarreradeDragones::CarreradeDragones() {}

void CarreradeDragones::InscribirDragon(cDragon* Dragon) {
    Competidores.push_back(Dragon);
}

void CarreradeDragones::IniciarCarrera() {
    cout << "¡Inicia la Carrera de Dragones!" << endl;
    for (auto dragon : Competidores) {
        cout << dragon->getNombre() << " empieza la carrera." << endl;
    }
    // Lógica de la carrera de dragones
}
