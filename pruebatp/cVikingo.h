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
	cDragon* miDragon;
	vector<cDragon*> dragonesMatados; // vector de punteros a cDragon

public:
	cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, cDragon* Dragoncito, int Fuerza);
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
	void Trabajar();
	static void AtacarDragones();
	void registrarDragonMatado(cDragon* dragon);
	void mostrarDragonesMatados();

	~cVikingo();
};
