#include "cBatalladeDragones.h"

cBatalladeDragones::cBatalladeDragones(vector<cVikingo*> Vikingos_isla, vector<cDragon*> Dragones_isla)
{
	this->Vikingos_isla = Vikingos_isla;
	this->Dragones_isla = Dragones_isla;
}

int cBatalladeDragones::mainB()
{
    BatalladeDragones(Vikingos_isla, Dragones_isla);
    return 0;
}

void cBatalladeDragones::BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla)
{
    cout << "La aldea esta en peligro! Preparense para la batalla contra los dragones malos!" << endl;
    cout << endl;
    cVikingo::AtacarDragones();

    for (cVikingo* vik : Vikingos_isla) {
        vik->Trabajar();
    }
 
    // Filtrar dragones malos (no domados)
    vector<cDragon*> dragonesMalos;
    for (auto dragon : Dragones_isla) {
        if (!dragon->getEstado()) {
            dragonesMalos.push_back(dragon);
        }
    }

    // Verificar si hay dragones malos para combatir
    if (dragonesMalos.empty()) {
        cout << "No hay dragones malos para combatir." << endl;
        return;
    }

    // Seleccionar aleatoriamente un vikingo y un dragón malo
    cVikingo* vikingo = Vikingos_isla[rand() % Vikingos_isla.size()];
    cDragon* dragonMalo = dragonesMalos[rand() % dragonesMalos.size()];

    cout << "El vikingo " << vikingo->getNombre() << " se enfrenta al dragon " << dragonMalo->getNombre() << "." << endl;

    // Comparar fuerza del vikingo con resistencia del dragón
    if (vikingo->getFuerza() >= dragonMalo->getResistencia()) {
        cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragonMalo->getNombre() << "!" << endl;
        vikingo->registrarDragonMatado(dragonMalo->getNombre());

        // Eliminar el dragón de la lista de dragones
        auto it = find(Dragones_isla.begin(), Dragones_isla.end(), dragonMalo);
        if (it != Dragones_isla.end()) {
            delete* it;
            Dragones_isla.erase(it);
        }
    }
    else {
        cout << "El dragon " << dragonMalo->getNombre() << " ha vencido al vikingo " << vikingo->getNombre() << "." << endl;
    }
}

cBatalladeDragones::~cBatalladeDragones()
{
}
