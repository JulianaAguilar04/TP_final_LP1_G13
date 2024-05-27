#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "cPersona.h"
#include "cDragon.h"

using namespace std;

class cVikingo:public cPersona
{
private:
	string Posicion;
	cDragon* miDragon; //relación entre dragon y vikingo, posible lista de dragones matados

public:
	cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string posicion, cDragon &Dragoncito);
	string to_string();
	/*string getNombre();
	string getApellido();
	string getPosicion();
	bool DragonesTerminados();
	void setNombre(string Nombre);
	void setApellido(string Apellido);
	void setPosicion(string Posicion);
	void Trabajar();
	void AtacarDragones();
	*/
	~cVikingo();
};
