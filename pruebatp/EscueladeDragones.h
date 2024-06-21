/* #pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class cDragon;

// void EscueladeDragones(&Dragones_isla);


#pragma once
#include <vector>
using namespace std;

class cDragon;

// void EscueladeDragones(vector<cDragon*>& Dragones_isla);
void EstudioDeDragones(vector<cDragon*>& Dragones_isla);
void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
void EntrenarDragones(vector<cDragon*>& Dragones_isla);
*/ 
#pragma once
#include <iostream>
#include <vector>
#include "cJinete.h"
#include "cDragon.h"

using namespace std;

class EscueladeDragones {
private:
    string Nombre;
    vector<cJinete*> Alumnos;
    vector<cDragon*> Dragones;

public:
    EscueladeDragones(string Nombre);
    void AgregarJinete(cJinete* Jinete);
    void AgregarDragon(cDragon* Dragon);
    void ImprimirEstado();
};
