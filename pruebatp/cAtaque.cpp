#include "cAtaque.h"

cAtaque::cAtaque(string Tipo, string Danio, string Alcance)
{
	this->Tipo = Tipo;
	this->Danio = Danio;
	this->Alcance = Alcance;

}

string cAtaque::getTipo()
{
	return Tipo;
}

string cAtaque::getDanio()
{
	return Danio;
}

string cAtaque::getAlcance()
{
	return Alcance;
}

void cAtaque::setTipo(string Tipo)
{
	this->Tipo = Tipo;
}

void cAtaque::setDanio(string Danio)
{
	this->Danio = Danio;;
}

void cAtaque::setAlcance(string Alcance)
{
	this->Alcance = Alcance;
}

string cAtaque::to_string()
{
	stringstream ss;
	ss << "Tipo:" << Tipo << endl;
	ss << "Danio:" << Danio << endl;
	ss << "Alcance:" << Alcance << endl;
	return ss.str();
}

ostream& operator<<(ostream& os, cAtaque& a)
{
	os << "Tipo:" << a.Tipo << endl;
	os << "Danio:" << a.Danio << endl;
	os << "Alcance: " << a.Alcance << endl;
	return os;
}

cAtaque::~cAtaque()
{
}