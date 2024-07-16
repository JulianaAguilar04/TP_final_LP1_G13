#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "cJinete.h"

using namespace std;

inline void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#endif
};

class EmpateException : public exception {
public:
    const char* what() const noexcept override {
        return "Empate: Dos o más jinetes recolectaron la misma cantidad de ovejas.";
    }
};

class NingunJineteRecolectaException : public exception {
public:
    const char* what() const noexcept override {
        return "Ningun jinete recolecto ovejas.";
    }
};

class cCarreradeDragones {
private:
    vector<cJinete*> jinetes;

public:
    cCarreradeDragones(vector<cJinete*>& Jinetes_isla);
    int mainC();
    void iniciarCarrera();
    void contarRegreso();
    void anunciarGanador();
    ~cCarreradeDragones();
};


/*

LO COMENTO PARA HACERLO DE NUEVO Y VER QUE FALLA (15/07 -15hs)
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class cCarreradeDragones {
public:
    cCarreradeDragones(vector<cJinete*>& Jinetes_isla);
    void iniciarCarrera();

private:
    vector<cJinete*>& jinetes;
    void contarRegreso();
};

*/

