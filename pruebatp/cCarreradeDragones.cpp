#include "cCarreradeDragones.h"

cCarreradeDragones::cCarreradeDragones(vector<cJinete*>& Jinetes_isla) : jinetes(Jinetes_isla) {
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla del generador de números aleatorios
}

int cCarreradeDragones::mainC() {
    try {
        iniciarCarrera();
        anunciarGanador();
    }
    catch (const EmpateException& e) {
        cout << e.what() << endl;
    }
    catch (const NingunJineteRecolectaException& e) {
        cout << e.what() << endl;
    }
    return 0;
}

void cCarreradeDragones::iniciarCarrera() {
    cout << "¡La carrera ha comenzado!" << endl;

    // Reiniciar el conteo de ovejas antes de la carrera
    for (auto& jinete : jinetes) {
        *jinete += -jinete->getNumeroOvejas(); // Restablecer el conteo a 0
    }
    contarRegreso();

    for (int i = 0; i < jinetes.size(); ++i) {
        int ovejasRecogidas = rand() % 100;
        *jinetes[i] += ovejasRecogidas; // Usando la sobrecarga del operador +=
        cout << jinetes[i]->getNombre() << " ha recogido " << ovejasRecogidas << " ovejas." << endl;
    }
}

void cCarreradeDragones::contarRegreso() {
    for (int i = 10; i >= 0; --i) {
        cout << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1)); // Pausar un segundo entre cada número
    }
}

void cCarreradeDragones::anunciarGanador() {
    int maxOvejas = -1;
    vector<string> ganadores;

    for (const auto& jinete : jinetes) {
        int ovejas = jinete->getNumeroOvejas();
        if (ovejas > maxOvejas) {
            maxOvejas = ovejas;
            ganadores.clear();
            ganadores.push_back(jinete->getNombre());
        }
        else if (ovejas == maxOvejas) {
            ganadores.push_back(jinete->getNombre());
        }
    }

    if (maxOvejas == 0) {
        throw NingunJineteRecolectaException();
    }
    else if (ganadores.size() > 1) {
        throw EmpateException();
    }
    else {
        cout << "¡El ganador es " << ganadores[0] << " con " << maxOvejas << " ovejas recolectadas!" << endl;
    }
}

cCarreradeDragones::~cCarreradeDragones() {
}
