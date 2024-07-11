#pragma once
#include "cDragon.h"

class cEmbestida:public cDragon
{
private:
	int velocidad;
	int agilidad;
	int fuerzaImpacto;
public:
	cEmbestida (string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Agilidad, int Fuerza, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, /*Velocidad, Resistencia*/ Habilidades, miAtaque), agilidad(Agilidad), velocidad(Velocidad), fuerzaImpacto(Fuerza) {};
	void EntrenarEmbestida(string tipoEntrenamiento, cJinete& jinete);
	void DesarrollarEstrategiaEmbestida(const string& tipo);
	~cEmbestida() {};
};

