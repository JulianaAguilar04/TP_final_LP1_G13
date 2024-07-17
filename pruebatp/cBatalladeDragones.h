#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "cDragon.h"
#include "cVikingo.h"

using namespace std;

inline void limpiarPantallaB()
{
#ifdef _WIN32
	system("cls");
#endif
};

class cJinete;

class cBatalladeDragones {
private:
	vector<cDragon*> Dragones_isla;
	vector<cVikingo*> Vikingos_isla;

public:
	cBatalladeDragones(vector<cVikingo*> Vikingos_isla, vector<cDragon*> Dragones_isla);
	int mainB();
	void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla);
	void mostrarLogrosVikingos();
	~cBatalladeDragones();
};

