#pragma once
#include "cDragon.h"

class cRastreadora:public cDragon
{
public:
	cRastreadora(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Resistencia, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, Velocidad, Resistencia, Habilidades, miAtaque) {};
	~cRastreadora() {};
};

