#include "cPersona.h"

cPersona::cPersona(string Nombre, string Apellido, string Apodo, string FecNac, int Fuerza)
{
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Apodo = Apodo;
	this->FecNac = FecNac;
    this->Fuerza = Fuerza;
}

string cPersona::to_string() const
{
	stringstream ss;
	ss << "Nombre:" << Nombre << endl;
	ss << "Apellido:" << Apellido << endl;
	ss << "Apodo:" << Apodo << endl;
	ss << "Fecha de nacimiento:" << FecNac << endl;
	ss << "Fuerza: " << Fuerza << endl;
	return ss.str();
}

cPersona::~cPersona()
{
}

/*ostream& operator<<(ostream& os, cPersona& p)
{
	os << "Nombre:" << p.Nombre << endl;
	os << "Apellido:" << p.Apellido << endl;
	os << "Apodo:" << p.Apodo << endl;
	os << "Fecha de nacimiento:" << p.FecNac << endl;
	return os;
}
*/ 

ostream& operator<<(ostream& os, cPersona& p)
{
	os << p.to_string();
	return os;
}

string cPersona::getNombre() const
{
	return Nombre;
}

int cPersona::getFuerza() const
{
	return Fuerza;
}


