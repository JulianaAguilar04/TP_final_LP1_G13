#pragma once
#include <iostream>
#include <cstdlib>
#include "cEscueladeDragones.h"
#include "cBatalladeDragones.h"
#include "cCarreradeDragones.h"
using namespace std;
class cEscueladeDragones;
class cBatalladeDragones;
class cCarreradeDragones;

class cIslaBerk
{
private:
	vector<cJinete*> Jinetes_isla;
	vector<cDragon*>Dragones_isla;
	vector<cVikingo*>Vikingos_isla;
	cEscueladeDragones* Escuela; //relación composicion
	cBatalladeDragones* Batalla;
	cCarreradeDragones* Carrera;
	
public:
	cIslaBerk(vector<cJinete*> Jinetes_isla, vector<cDragon*>Dragones_isla, vector<cVikingo*>Vikingos_isla);
	int mainBerk();
	~cIslaBerk();
};

