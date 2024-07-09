#pragma once
#include <iostream>
#include "cEscueladeDragones.h"
#include "cBatalladeDragones.h"
using namespace std;
class cEscueladeDragones;
class cBatalladeDragones;

class cIslaBerk
{
private:
	vector<cJinete*> Jinetes_isla;
	vector<cDragon*>Dragones_isla;
	vector<cVikingo*>Vikingos_isla;
	cEscueladeDragones* Escuela; //relación composicion
	cBatalladeDragones* Batalla;
	
public:
	cIslaBerk(vector<cJinete*> Jinetes_isla, vector<cDragon*>Dragones_isla, vector<cVikingo*>Vikingos_isla);
	int mainBerk();
	~cIslaBerk();
};

