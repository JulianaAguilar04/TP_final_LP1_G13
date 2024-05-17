#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "cDragon.h"

using namespace std;

class cVikingo
{
private:
	string Nombre;
	string Apellido;
	string Posicion;
	//cDragon* miDragon;


public:
	cVikingo();
	string getNombre();
	string getApellido();
	string getPosicion();
	bool DragonesTerminados();
	void setNombre(string Nombre);
	void setApellido(string Apellido);
	void setPosicion(string Posicion);
	void Trabajar();
	void AtacarDragones();
	string to_string();
	~cVikingo();
};
