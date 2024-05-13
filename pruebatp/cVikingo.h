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
	cVikingo(string Nombre, string Apellido, string Posicion);
	string getNombre();
	string getApellido();
	string getPosicion();
	void setNombre(string nuevoNombre);
	void setApellido(string nuevaPosicion);
	void setPosicion(string nuevaPosicion);
	void Trabajar();
	bool DragonesTerminados();
	void AtacarDragones();
};
