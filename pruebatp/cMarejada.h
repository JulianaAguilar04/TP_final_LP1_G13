#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cMarejada:public cDragon
{
private:
	int adaptabilidad;
public:
	cMarejada(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, /*int Velocidad, int Resistencia,*/ vector<string>& Habilidades, cAtaque* miAtaque, int adaptabilidad) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, /*Velocidad, Resistencia,*/ Habilidades, miAtaque), adaptabilidad(adaptabilidad) {};
	void Entrenar(const string tipoEntrenamiento,const cJinete& jinete);
	void DesarrollarEstrategia(const string& tipo) override;
	~cMarejada() override;
};

