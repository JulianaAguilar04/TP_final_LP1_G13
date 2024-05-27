#include "cVikingo.h"
#include "cPersona.h"

//constructor por parametro
cVikingo::cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string posicion, cDragon& Dragoncito):cPersona(Nombre, Apellido, Apodo, FecNac) {
	this->Posicion = Posicion;
	miDragon = &Dragoncito;
}
/*
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
}*/
string cVikingo::to_string() {
	stringstream ss;
	cPersona::to_string();
	ss << "Posicion:" << Posicion;
	ss << miDragon->to_string();
	return ss.str();
}

cVikingo::~cVikingo()
{
}
