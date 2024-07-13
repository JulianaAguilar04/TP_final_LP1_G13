#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cMarejada:public cDragon
{
private:
	int adaptabilidad;
public:
	cMarejada(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Resistencia, int adaptabilidad,  vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, Resistencia, Habilidades, miAtaque), adaptabilidad(adaptabilidad) {};
	static cMarejada* AltaDragon();
	void Entrenar(const string tipoEntrenamiento,const cJinete& jinete);
	void DesarrollarEstrategia(const string& tipo) override;
	~cMarejada() override;
};

