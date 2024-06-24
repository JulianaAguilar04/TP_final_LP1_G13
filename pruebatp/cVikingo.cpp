#include "cVikingo.h"

//constructor por parametro
cVikingo::cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, cDragon* Dragoncito, int Fuerza):cPersona(Nombre, Apellido, Apodo, FecNac, Fuerza) {
	this->Posicion = Posicion;
	miDragon = Dragoncito;
}

string cVikingo::getNombre()
{
	return Nombre;
}
void cVikingo::mostrarInfo(ostream& os) const
{
	os << "Nombre:" << Nombre << endl;
	os << "Apellido:" << Apellido << endl;
	os << "Apodo:" << Apodo << endl;
	os << "Fecha de nacimiento:" << FecNac << endl;
	os << "Posicion:" << Posicion << endl;
	os << "Fuerza:" << Fuerza << endl;
	if (miDragon) {
		os << "Dragon:" << miDragon->getNombre() << endl;
	}
	else {
		os << "Sin dragon asignado" << endl;
	}

}

ostream& operator<<(ostream& os, const cVikingo& v)
{
	v.mostrarInfo(os);
	return os;
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

vector<string> cVikingo::getdragonesMatados()
{
	return dragonesMatados;
}

string cVikingo::to_string()
{
	stringstream ss;
	ss << "Nombre:" << Nombre << endl;
	ss << "Apellido:" << Apellido << endl;
	ss << "Posicion:" << Posicion << endl;
	return ss.str();
}

void cVikingo::AtacarDragones() {
	cout << "¡Todos los vikingos, prepárense para la batalla contra los dragones!" << endl;
}


void cVikingo::registrarDragonMatado(const string& nombreDragon) {
	dragonesMatados.push_back(nombreDragon);
}

void cVikingo::mostrarDragonesMatados() {
	cout << "Dragones matados por " << Nombre << ":" << endl;
	for (const auto& nombre : dragonesMatados) {
		cout << nombre << " "<<endl;
	}
	cout << endl;
}

/*
string cVikingo::to_string() {
	stringstream ss;
	ss << cPersona::to_string();
	ss << "Posicion:" << Posicion;
	ss << miDragon->to_string();
	return ss.str();
}*/

cVikingo::~cVikingo()
{
}

