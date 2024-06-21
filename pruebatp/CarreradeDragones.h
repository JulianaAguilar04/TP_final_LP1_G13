#pragma once
#include <iostream>
#include <vector>
#include "cDragon.h"

using namespace std;

class CarreradeDragones {
private:
    vector<cDragon*> Competidores;

public:
    CarreradeDragones();
    void InscribirDragon(cDragon* Dragon);
    void IniciarCarrera();
};

