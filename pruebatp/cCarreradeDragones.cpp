#include "cCarreradeDragones.h"

cCarreradeDragones::cCarreradeDragones(vector<cJinete*>& Jinetes_isla) : jinetes(Jinetes_isla) {}

int cCarreradeDragones::mainC()
{
    iniciarCarrera();
    return 0;
}

void cCarreradeDragones::iniciarCarrera() {
    vector<int> conteoOvejas(jinetes.size(), 0);

    cout << "¡La carrera ha comenzado!" << endl;

    for (size_t i = 0; i < jinetes.size(); ++i) {
        int ovejasRecogidas = rand() % 10; // Simula la recolección de 0 a 9 ovejas
        conteoOvejas[i] = ovejasRecogidas;
        cout << jinetes[i]->getNombre() << " ha recogido " << ovejasRecogidas << " ovejas." << endl;
    }

    contarRegreso();

    // Anunciar el ganador
    int maxOvejas = -1;
    string ganador;

    for (size_t i = 0; i < jinetes.size(); ++i) {
        if (conteoOvejas[i] > maxOvejas) {
            maxOvejas = conteoOvejas[i];
            ganador = jinetes[i]->getNombre();
        }
    }

    if (!ganador.empty()) {
        cout << "¡El ganador es " << ganador << " con " << maxOvejas << " ovejas recolectadas!" << endl;
    }
    else {
        cout << "No hay ganador, ningún jinete recogió ovejas." << endl;
    }
}

cCarreradeDragones::~cCarreradeDragones()
{
}

void cCarreradeDragones::contarRegreso() {
    for (int i = 10; i >= 0; --i) {
        cout << i << "..." << endl;
    }
}


/*
LO COMENTO PARA HACERLO NUEVAMENTE MAS LIMPIO (15/07 - 15hs)

#include "cCarreradeDragones.h"
#include "cJinete.h"

cCarreradeDragones::cCarreradeDragones(vector<cJinete*>& Jinetes_isla) : jinetes(Jinetes_isla) {}

void cCarreradeDragones::iniciarCarrera() {
    vector<int> conteoOvejas(jinetes.size(), 0);

    cout << "¡La carrera ha comenzado!" << endl;

    for (size_t i = 0; i < jinetes.size(); ++i) {
        int ovejasRecogidas = rand() % 10; // Simula la recolección de 0 a 9 ovejas
        conteoOvejas[i] = ovejasRecogidas;
        cout << jinetes[i]->getNombre() << " ha recogido " << ovejasRecogidas << " ovejas." << endl;
    }

    contarRegreso();

    // Anunciar el ganador
    int maxOvejas = -1;
    string ganador;

    for (size_t i = 0; i < jinetes.size(); ++i) {
        if (conteoOvejas[i] > maxOvejas) {
            maxOvejas = conteoOvejas[i];
            ganador = jinetes[i]->getNombre();
        }
    }

    cout << "¡El ganador es " << ganador << " con " << maxOvejas << " ovejas recolectadas!" << endl;
}

void cCarreradeDragones::contarRegreso() {
    for (int i = 10; i >= 0; --i) {
        cout << i << "..." << endl;
    }
}

/*
/#include "cCarreradeDragones.h"
#include "cJinete.h"

cCarreradeDragones::cCarreradeDragones(vector<cJinete*> Jinetes_isla) : jinetes(jinetes) {
    srand(static_cast<unsigned>(time(0))); // Inicializa la semilla aleatoria
}

void cCarreradeDragones::iniciarCarrera() {
    cout << "¡La carrera de dragones ha comenzado!" << endl;
    for (auto& jinete : jinetes) {
        recolectarOvejas(jinete);
    }

    // Conteo regresivo
    cout << "¡CORRE EL TIEMPO!" << endl;
    for (int i = 10; i >= 0; --i) {
        cout << i << "..." << endl;
    }

    // Determina el ganador
    cJinete* ganador = nullptr;
    int maxOvejas = 0;
    for (auto& jinete : jinetes) {
        if (jinete->getNumeroOvejas() > maxOvejas) {
            maxOvejas = jinete->getNumeroOvejas();
            ganador = jinete;
        }
    }

    cout << "¡El ganador es " << ganador->getNombre() << " con " << maxOvejas << " ovejas recolectadas!" << endl;
}

void cCarreradeDragones::recolectarOvejas(cJinete* jinete) {
    int ovejasRecolectadas = rand() % 10; // Simula la recolección de entre 0 y 9 ovejas
    jinete->incrementarOvejas(ovejasRecolectadas);
    cout << jinete->getNombre() << " ha recolectado " << ovejasRecolectadas << " ovejas." << endl;
}

xdxdxd 

*/