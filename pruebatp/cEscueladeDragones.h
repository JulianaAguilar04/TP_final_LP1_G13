#pragma once
#include <iostream>
#include <vector>
#include "cJinete.h"
#include "cDragon.h"
#include "cVikingo.h"
#include "cFogonera.h"
#include "cMarejada.h"
#include "cEmbestida.h"
using namespace std;

inline void limpiarPantallaE()
{
#ifdef _WIN32
	system("cls");
#endif
};

class cEscueladeDragones
{
private:
	vector<cJinete*> Jinetes_isla;
	vector<cDragon*> Dragones_isla;
public:
	cEscueladeDragones(vector<cJinete*> Jinetes_isla, vector<cDragon*> Dragones_isla);
	int mainE();
	void EstudioDeDragones(vector<cDragon*> &Dragones_isla);
	void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
	void EntrenarDragones(vector<cJinete*>& Jinetes_isla);
	~cEscueladeDragones();

};

