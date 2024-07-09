#pragma once
#include <iostream>
#include "cDragon.h"
#include "cVikingo.h"
#include <vector>
using namespace std;
class cJinete;

class cBatalladeDragones
{
private:
	vector<cDragon*> Dragones_isla;
	vector<cVikingo*> Vikingos_isla;

public:
	cBatalladeDragones(vector<cVikingo*>Vikingos_isla, vector<cDragon*> Dragones_isla);
	int mainB();
	void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla);
	~cBatalladeDragones();
};

