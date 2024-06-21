#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "cDragon.h"
#include "cVikingo.h"
#include "cJinete.h"
using namespace std;

class BatalladeDragones {
private:
    vector<cDragon*> dragonesMalos;
    vector<cDragon*> dragonesBuenos;
    vector<cVikingo*> vikingos;
    vector<cJinete*> jinetes;
public:
    BatalladeDragones(vector<cDragon*>& dragones, vector<cVikingo*>& vikingos, vector<cJinete*>& jinetes);
    void AvisarAldea();
    void Combatir();
    void AnunciarGanador(cPersona* ganador);
    void FiltrarDragones(vector<cDragon*>& dragones); // Nuevo método para filtrar dragones
};

/*#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cVikingo;
class cDragon;

void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla);*/

