#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cPersona.h"
#include "cDragon.h"

using namespace std;

class cVikingo : public cPersona {
private:
	string Posicion;
	vector<cDragon*> dragonesMatados;

public:
	cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, int Fuerza);
	string to_string();

	void mostrarInfo(ostream& os) const;
	friend ostream& operator<<(ostream& os, const cVikingo& v);

	string getNombre();
	string getApellido();
	string getPosicion();
	vector<cDragon*> getDragonesMatados();
	void setNombre(string Nombre);
	void setApellido(string Apellido);
	void setPosicion(string Posicion);
	cVikingo& operator += (cDragon *d); //sobrecarga operador 
	cVikingo operator += (int);
	void Trabajar();
	static void AtacarDragones();
	void mostrarDragonesMatados();

	~cVikingo();
};
