#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class cPersona
{
protected:
	string Nombre;
	string Apellido;
	string Apodo;
	string FecNac;
public:
	cPersona(string Nombre, string Apellido, string Apodo, string FecNac);
	virtual string to_string();
	~cPersona();
};

