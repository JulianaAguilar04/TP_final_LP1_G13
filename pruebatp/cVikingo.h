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
	vector<string> dragonesMatados;

public:
	cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, cDragon *Dragoncito, int Fuerza);
	string to_string();

	void mostrarInfo(ostream& os) const;
	friend ostream& operator<<(ostream& os,const cVikingo& v);
	
	string getNombre();
	string getApellido ();
	string getPosicion ();
	vector <string> getdragonesMatados();
	void setNombre(string Nombre);
	void setApellido(string Apellido);
	void setPosicion(string Posicion);
	void Trabajar();
	static void AtacarDragones();
	void registrarDragonMatado(const string& nombreDragon);
	void mostrarDragonesMatados();

	~cVikingo();
};
