#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cFogonera:public cDragon
{
private:
	int precision;
	int resistenciaAlCalor;

public: 
	cFogonera(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Resistencia, int pres, int resCalor, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, Resistencia, Habilidades, miAtaque), resistenciaAlCalor(resCalor), precision(pres) {};
	static cFogonera* AltaDragon();
	void Entrenar(const string tipoEntrenamiento,const cJinete &jinete);
	void DesarrollarEstrategia(const string &tipo) override;
	~cFogonera() override;
};

