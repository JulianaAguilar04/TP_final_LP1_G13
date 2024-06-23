#pragma once
#include "cDragon.h"

class cMarejada:public cDragon
{
public:
	cMarejada(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Resistencia, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, Velocidad, Resistencia, Habilidades, miAtaque) {};
	~cMarejada() {};
};

