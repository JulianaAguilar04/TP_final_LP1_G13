#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "cDragon.h"
using namespace std;

class cPersona
{
protected:
	string Nombre;
	string Apellido;
	string Apodo;
	string FecNac;
    int Fuerza; 
public:
	cPersona(string Nombre, string Apellido, string Apodo, string FecNac, int Fuerza);
	virtual string to_string() const;
	friend ostream& operator <<(ostream& os,const cPersona& p);
	virtual void mostrarInfo(ostream& os) const = 0;
    string getNombre() const;
    int getFuerza() const;
	virtual ~cPersona() = 0;
};
