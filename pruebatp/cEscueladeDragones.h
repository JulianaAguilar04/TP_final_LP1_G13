#pragma once
#include <iostream>
#include <vector>
#include "cJinete.h"
#include "cDragon.h"
#include "cVikingo.h"
using namespace std;


class cEscueladeDragones
{
private:
	vector<cJinete*> Jinetes_isla;
	vector<cDragon*> Dragones_isla;
public:
	cEscueladeDragones(vector<cJinete*> Jinetes_isla, vector<cDragon*> Dragones_isla);
	int mainE();
	void MOSTRAR();
	void EstudioDeDragones(vector<cDragon*> &Dragones_isla);
	void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
	void EntrenarDragones(vector<cJinete*>& Jinetes_isla);
	~cEscueladeDragones();

};

