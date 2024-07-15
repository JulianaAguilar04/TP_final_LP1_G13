#pragma once
#include <vector>
#include <iostream>
#include "cJinete.h"

using namespace std;

class cCarreraDeDragones {
public:
    cCarreraDeDragones(vector<cJinete*>& Jinetes_isla);
    void iniciarCarrera();

private:
    vector<cJinete*>& jinetes;
    void contarRegreso();
};


/*

LO COMENTO PARA HACERLO DE NUEVO Y VER QUE FALLA (15/07 -15hs)
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class cCarreraDeDragones {
public:
    cCarreraDeDragones(vector<cJinete*>& Jinetes_isla);
    void iniciarCarrera();

private:
    vector<cJinete*>& jinetes;
    void contarRegreso();
};

*/

