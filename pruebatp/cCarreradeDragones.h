#pragma once
#include <vector>
#include <iostream>
#include "cJinete.h"
using namespace std;
inline void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#endif
};

class cCarreradeDragones {
private:
    vector<cJinete*>& jinetes;
    void contarRegreso();
public:
    cCarreradeDragones(vector<cJinete*>& Jinetes_isla);
    int mainC();
    void iniciarCarrera();
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

