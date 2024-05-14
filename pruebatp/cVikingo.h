#pragma once
#include <iostream>
#include <string>

using namespace std;

class cVikingo
{
private:
	string Nombre;
	string Apellido;
	string Posicion;

public:
	cVikingo();
	string getNombre();
	string getApellido();
	string getPosicion();
	bool DragonesTerminados();
	void setNombre(string nuevoNombre);
	void setApellido(string nuevaPosicion);
	void setPosicion(string nuevaPosicion);
	void Trabajar();
	void AtacarDragones();
};
