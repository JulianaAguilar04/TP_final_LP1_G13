/*#include "BatalladeDragones.h"
#include "cDragon.h"
#include "cVikingo.h"
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
*/
/*
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones) {
    cVikingo::AtacarDragones(); // Enviar mensaje a los vikingos

    cout << "La batalla ha comenzado!" << endl;

    // Simulación simple de la batalla
    srand(time(0));
    for (auto& vikingo : vikingos) {
        if (dragones.empty()) {
            cout << "Todos los dragones han sido derrotados!" << endl;
            return;
        }

        int dragonIndex = rand() % dragones.size();
        cDragon* dragon = dragones[dragonIndex];

        // Ejemplo simple de combate: 50% de probabilidad de que el vikingo gane
        if (rand() % 2 == 0) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragon->getNombre() << endl;
            vikingo->registrarDragonMatado(dragon->getNombre());
            dragones.erase(dragones.begin() + dragonIndex); // Eliminar dragón derrotado
            delete dragon; // Liberar memoria del dragón eliminado
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " ha derrotado al vikingo " << vikingo->getNombre() << endl;
        }
    }

    cout << "La batalla ha terminado!" << endl;
}
*/

#include "BatalladeDragones.h"

BatalladeDragones::BatalladeDragones() {}

void BatalladeDragones::InscribirDragon(cDragon* Dragon) {
    Participantes.push_back(Dragon);
}

void BatalladeDragones::IniciarBatalla() {
    cout << "¡Inicia la Batalla de Dragones!" << endl;
    for (auto dragon : Participantes) {
        cout << dragon->getNombre() << " entra en la arena." << endl;
    }
    // Lógica de la batalla de dragones
}
