#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cEmbestida:public cDragon
{
private:
	int velocidad;
	int agilidad;
	int fuerzaImpacto;
public:
	cEmbestida (string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Agilidad, int Fuerza, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, /*Velocidad, Resistencia*/ Habilidades, miAtaque), agilidad(Agilidad), velocidad(Velocidad), fuerzaImpacto(Fuerza) {};
	void Entrenar(const string tipoEntrenamiento, const cJinete& jinete) override;
	void DesarrollarEstrategia(const string& tipo) override;
	~cEmbestida() override;
};

