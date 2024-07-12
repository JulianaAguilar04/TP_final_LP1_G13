#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cFogonera:public cDragon
{
private:
	int precision;
	int resistenciaAlCalor;

public: 
	cFogonera(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, /*int Velocidad, int Resistencia,*/ vector<string>& Habilidades, cAtaque* miAtaque, int pres, int resCalor) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, /*Velocidad, Resistencia,*/ Habilidades, miAtaque), resistenciaAlCalor(resCalor), precision(pres) {};
	void Entrenar(const string tipoEntrenamiento,const cJinete &jinete) override;
	void DesarrollarEstrategia(const string &tipo) override;
	~cFogonera() override;
};

