#include "BatalladeDragones.h"
#include <cstdlib>
#include <ctime>

BatalladeDragones::BatalladeDragones(vector<cDragon*>& dragones, vector<cVikingo*>& vikingos, vector<cJinete*>& jinetes) {
    srand(time(0));
    FiltrarDragones(dragones);
    this->vikingos = vikingos;
    this->jinetes = jinetes;
}

void BatalladeDragones::FiltrarDragones(vector<cDragon*>& dragones) {
    for (auto dragon : dragones) {
        if (dragon->getEstado()) {
            dragonesBuenos.push_back(dragon);
        }
        else {
            dragonesMalos.push_back(dragon);
        }
    }
}

void BatalladeDragones::AvisarAldea() {
    cout << "¡La aldea está en peligro!" << endl;
}

void BatalladeDragones::Combatir() {
    if (dragonesMalos.empty() || (vikingos.empty() && jinetes.empty())) {
        cout << "No hay suficientes dragones malos o combatientes para realizar la batalla." << endl;
        return;
    }

    // Seleccionar un vikingo/jinete aleatorio
    cPersona* combatiente;
    if (!vikingos.empty() && !jinetes.empty()) {
        if (rand() % 2 == 0) {
            combatiente = vikingos[rand() % vikingos.size()];
        }
        else {
            combatiente = jinetes[rand() % jinetes.size()];
        }
    }
    else if (!vikingos.empty()) {
        combatiente = vikingos[rand() % vikingos.size()];
    }
    else {
        combatiente = jinetes[rand() % jinetes.size()];
    }

    // Seleccionar un dragón malo aleatorio
    cDragon* dragonMalo = dragonesMalos[rand() % dragonesMalos.size()];

    // Realizar el combate
    int fuerzaCombatiente = combatiente->getFuerza();
    if (fuerzaCombatiente > dragonMalo->getResistencia()) {
        cout << "¡" << combatiente->getNombre() << " ha derrotado a " << dragonMalo->getNombre() << "!" << endl;
        // Eliminar dragón malo de la lista
        dragonesMalos.erase(remove(dragonesMalos.begin(), dragonesMalos.end(), dragonMalo), dragonesMalos.end());
        // Añadir dragón malo a la lista de dragones matados por el combatiente
        combatiente->addDragonMatado(dragonMalo);
        // Anunciar ganador
        AnunciarGanador(combatiente);
    }
    else {
        cout << "¡" << dragonMalo->getNombre() << " ha derrotado a " << combatiente->getNombre() << "!" << endl;
        // Anunciar ganador
        AnunciarGanador(dragonMalo);
    }
}

void BatalladeDragones::AnunciarGanador(cPersona* ganador) {
    cout << "¡El ganador es " << ganador->getNombre() << "!" << endl;
}

void BatalladeDragones::AnunciarGanador(cDragon* ganador) {
    cout << "¡El ganador es el dragón " << ganador->getNombre() << "!" << endl;
}


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

