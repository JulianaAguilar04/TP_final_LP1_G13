#include "cVikingo.h"
cVikingo::cVikingo(string Nombre, string Apellido, string Posicion)
{
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Posicion = Posicion;
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
void cVikingo::setNombre(string nuevoNombre)
{
	Nombre = nuevoNombre;
}
void cVikingo::setApellido(string nuevoApellido)
{
	Apellido = nuevoApellido;
}
void cVikingo::setPosicion(string nuevaPosicion)
{
	Posicion = nuevaPosicion;
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

