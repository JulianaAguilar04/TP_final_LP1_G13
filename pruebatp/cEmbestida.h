#pragma once
#include "cDragon.h"
#include "cJinete.h"

class cEmbestida:public cDragon
{
private:
	int velocidad;
	int agilidad;
	int fuerzaImpacto;
	string EstrategiaAtaque(int opcion);
	string EstrategiaDefensa(int opcion);
public:
	cEmbestida (string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Resistencia, int Velocidad, int Agilidad, int Fuerza, vector<string>& Habilidades, cAtaque* miAtaque) : cDragon(Nombre, Caracteristica, Tamano, Color, Estado, Resistencia, Habilidades, miAtaque), agilidad(Agilidad), velocidad(Velocidad), fuerzaImpacto(Fuerza) {};
	static cEmbestida* AltaDragon();
	void Entrenar(const string tipoEntrenamiento, const cJinete& jinete);
	void DesarrollarEstrategia(const string& tipo) override;
	void print(ostream& os);
	~cEmbestida() override;
};

