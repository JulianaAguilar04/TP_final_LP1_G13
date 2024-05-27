#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class cPersona
{
public:
	string Nombre;
	string Apellido;
	string Apodo;
	string FecNac;
	cPersona(string Nombre, string Apellido, string Apodo, string FecNac);
	virtual string to_string();
	~cPersona();
};

