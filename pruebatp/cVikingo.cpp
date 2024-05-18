#include "cVikingo.h"

//constructor por defecto
cVikingo::cVikingo()
{
	this->Nombre = "Hipo";
	this->Apellido = "Horrendo";
	this->Posicion = "Piloto";
	miDragon = nullptr;
}
string cVikingo::getNombre()
{
	return Nombre;
}
string cVikingo::getApellido()
{
	return Apellido;
}
string cVikingo::getPosicion()
{
	return Posicion;
}
void cVikingo::setNombre(string Nombre)
{
	this->Nombre = Nombre;
}
void cVikingo::setApellido(string Apellido)
{
	this->Apellido = Apellido;
}
void cVikingo::setPosicion(string Posicion)
{
	this->Posicion = Posicion;
}

void cVikingo::Trabajar()
{
	//completar
}

bool cVikingo::DragonesTerminados()
{
	return false;
}

void cVikingo::AtacarDragones()
{
	//completar 
}

string cVikingo::to_string()
{
	stringstream ss;
	ss << "Nombre:" << Nombre << endl;
	ss << "Apellido:" << Apellido << endl;
	ss << "Posicion:" << Posicion << endl;
	return ss.str();
}

cVikingo::~cVikingo()
{
}

