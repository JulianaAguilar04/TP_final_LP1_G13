#include "cVikingo.h"

//constructor por defecto
cVikingo::cVikingo()
{
	this->Nombre = "Hipo";
	this->Apellido = "Horrendo";
	this->Posicion = "Piloto";
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

