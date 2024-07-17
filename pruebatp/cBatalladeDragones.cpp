#include "cBatalladeDragones.h"

cBatalladeDragones::cBatalladeDragones(vector<cVikingo*> Vikingos_isla, vector<cDragon*> Dragones_isla)
    : Vikingos_isla(Vikingos_isla), Dragones_isla(Dragones_isla) {}

int cBatalladeDragones::mainB() {
    int opcion;
    try {
        do {
            cout << "------CAMPO DE BATALLA------" << endl;
            cout << "1) Luchar" << endl;
            cout << "2) Logros" << endl;
            cout << "3) Salir" << endl;
            cin >> opcion;
            limpiarPantallaB();

            switch (opcion)
            {
            case 1:
                BatalladeDragones(Vikingos_isla, Dragones_isla);
                break;
            case 2:
                mostrarLogrosVikingos();
                break;
            case 3:
                cout << "Saliendo del campo de batalla..." << endl;
                break;
            default:
                cout << "Opcion invalida: Vuelva a intentarlo" << endl;
                break;
            }
            if (opcion != 3) {
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
                limpiarPantallaB();
            }

        } while (opcion != 3);
    }
    catch (const exception& e) {
        cout << "Error en la ejecucion del programa: " << e.what() << endl;
    }

    return 0;
}

void cBatalladeDragones::BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla) {

    try {
        cout << "La aldea esta en peligro! Preparense para la batalla contra los dragones malos!" << endl;
        cout << endl;
        cVikingo::AtacarDragones();

        for (cVikingo* vik : Vikingos_isla) {
            vik->Trabajar();
        }
        //me creo vector de dragones malos para pelear contra ellos
        vector<cDragon*> dragonesMalos;
        for (auto dragon : Dragones_isla) {
            //si el dragon no esta domado, es malo
            if (!dragon->getEstado()) {
                dragonesMalos.push_back(dragon);
            }
        }
        //chequeo que el vector no este vacio
        if (dragonesMalos.empty()) {
            cout << "No hay dragones malos para combatir." << endl;
            return;
        }

        //agarro un vikingo cualquiera para combatir
        cVikingo* vikingo = Vikingos_isla[rand() % Vikingos_isla.size()];

        //agarro un dragon cualquiera de la lista de dragones malos para combatir contra el vikingo
        cDragon* dragonMalo = dragonesMalos[rand() % dragonesMalos.size()];

        cout << "El vikingo " << vikingo->getNombre() << " se enfrenta al dragon " << dragonMalo->getNombre() << "." << endl;

        if (vikingo->getFuerza() >= dragonMalo->getResistencia()) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragonMalo->getNombre() << "!" << endl;
            //se le agrega el dragon a la lista de dragones matados por el vikingo
            *vikingo += dragonMalo;

            //utilizo find para encontrar el dragon en el vector de dragones malos
            auto it = find(Dragones_isla.begin(), Dragones_isla.end(), dragonMalo);
            if (it != Dragones_isla.end()) {
                //lo elimino de la lista de dragones de la isla
                Dragones_isla.erase(it);
            }
        }
        else {
            cout << "El dragon " << dragonMalo->getNombre() << " ha vencido al vikingo " << vikingo->getNombre() << "." << endl;
            auto it = find(Vikingos_isla.begin(), Vikingos_isla.end(), vikingo);
            if (it != Vikingos_isla.end()) {
                delete* it;
                //elimino el vikingo de la isla
                Vikingos_isla.erase(it);
            }
        }
    }
    catch (const bad_alloc& e) {
        cerr << "Error de asignacion de memoria: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error en la batalla de dragones: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Error desconocido en la batalla de dragones." << endl;
    }

}

void cBatalladeDragones::mostrarLogrosVikingos() {
  
    int index;
    cout << "Lista de Vikingos:" << endl;
    for (int i = 0; i < Vikingos_isla.size(); i++) {
        cout << i + 1 << ". " << Vikingos_isla[i]->getNombre() << endl;
    }
    cout << "Seleccione el vikingo para ver sus logros: ";
    cin >> index;

    if (index > 0 && index <= Vikingos_isla.size()) {
        cVikingo* vikingoSeleccionado = Vikingos_isla[index - 1];
        vikingoSeleccionado->mostrarDragonesMatados();

        vector<cDragon*> dragonesMatados = vikingoSeleccionado->getDragonesMatados();
        if (!dragonesMatados.empty()) {
            cout << "Seleccione un dragon para ver sus detalles (0 para volver): ";
            int dragonIndex;
            cin >> dragonIndex;

            if (dragonIndex > 0 && dragonIndex <= dragonesMatados.size()) {
                cDragon* dragonSeleccionado = dragonesMatados[dragonIndex - 1];
                cout << "Detalles del dragon " << dragonSeleccionado->getNombre() << ":" << endl;
                cout << *dragonSeleccionado << endl; 
            }
        }
        else {
            cout << "Este vikingo no ha matado ningun dragon." << endl;
        }
    }
    else {
        cout << "Indice de vikingo invalido." << endl;
    }
}

cBatalladeDragones::~cBatalladeDragones() {}


