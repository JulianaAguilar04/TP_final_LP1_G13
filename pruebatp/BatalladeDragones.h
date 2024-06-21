/*#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cVikingo;
class cDragon;

void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla);*/

#pragma once
#include <iostream>
#include <vector>
#include "cDragon.h"

using namespace std;

class BatalladeDragones {
private:
    vector<cDragon*> Participantes;

public:
    BatalladeDragones();
    void InscribirDragon(cDragon* Dragon);
    void IniciarBatalla();
};
