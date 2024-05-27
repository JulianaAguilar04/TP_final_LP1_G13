#include "cPersona.h"

cPersona::cPersona(string Nombre, string Apellido, string Apodo, string FecNac)
{
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Apodo = Apodo;
	this->FecNac = FecNac;
}

string cPersona::to_string()
{
	stringstream ss;
	ss << "Nombre:" << Nombre << endl;
	ss << "Apellido:" << Apellido << endl;
	ss << "Apodo:" << Apodo << endl;
	ss << "Fecha de nacimiento:" << FecNac << endl;
	return ss.str();
}

cPersona::~cPersona()
{
}
