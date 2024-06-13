#include "cPersona.h"

cPersona::cPersona(string Nombre, string Apellido, string Apodo, string FecNac)
{
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Apodo = Apodo;
	this->FecNac = FecNac;
}

string cPersona::to_string() const
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

ostream& operator<<(ostream& os, cPersona& p)
{
	os << "Nombre:" << p.Nombre << endl;
	os << "Apellido:" << p.Apellido << endl;
	os << "Apodo:" << p.Apodo << endl;
	os << "Fecha de nacimiento:" << p.FecNac << endl;
	return os;
}
