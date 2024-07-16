#include "cVikingo.h"

cVikingo::cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, cDragon* Dragoncito, int Fuerza)
	: cPersona(Nombre, Apellido, Apodo, FecNac, Fuerza), miDragon(Dragoncito), Posicion(Posicion) {}

string cVikingo::getNombre() {
	return Nombre;
}

void cVikingo::mostrarInfo(ostream& os) const {
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

ostream& operator<<(ostream& os, const cVikingo& v) {
	v.mostrarInfo(os);
	return os;
}

string cVikingo::getApellido() {
	return Apellido;
}

string cVikingo::getPosicion() {
	return Posicion;
}

void cVikingo::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

void cVikingo::setApellido(string Apellido) {
	this->Apellido = Apellido;
}

void cVikingo::setPosicion(string Posicion) {
	this->Posicion = Posicion;
}

void cVikingo::Trabajar() {
	if (Posicion == "Agricultor" || Posicion == "Agricultora") {
		cout << Nombre << " que es " << Posicion << " esta trabajando en la huerta cosechando cereales y vegetales." << endl;
		cout << endl;
	}
	else if (Posicion == "Ganadero" || Posicion == "Ganadera") {
		cout << Nombre << " que es " << Posicion << " esta trabajando en el campo con las ovejas." << endl;
		cout << endl;
	}
	else if (Posicion == "Herrero" || Posicion == "Herrera") {
		cout << Nombre << " que es " << Posicion << " esta trabajando en la herreria preparando el nuevo armamento de los vikingos." << endl;
		cout << endl;
	}
	else if (Posicion == "Constructor" || Posicion == "Constructora") {
		cout << Nombre << " que es " << Posicion << " esta ayudando a construir nuevos barcos y casas para los nuevos vikingos." << endl;
		cout << endl;
	}
	else if (Posicion == "Pescador" || Posicion == "Pescadora") {
		cout << Nombre << " que es " << Posicion << " esta en el Mar de Norte con los demás pescadores." << endl;
		cout << endl;
	}
}

vector<cDragon*> cVikingo::getDragonesMatados() {
	return dragonesMatados;
}

void cVikingo::AtacarDragones() {
	cout << "Todos los vikingos, dejen sus puestos de trabajo y preparense para la batalla contra los dragones!" << endl;
}

void cVikingo::registrarDragonMatado(cDragon* dragon) {
	dragonesMatados.push_back(dragon);
}

void cVikingo::mostrarDragonesMatados() {
	cout << "Dragones matados por " << Nombre << ":" << endl;
	for (const auto& dragon : dragonesMatados) {
		cout << dragon->getNombre() << " " << endl;
	}
	cout << endl;
}

string cVikingo::to_string() {
	stringstream ss;
	ss << cPersona::to_string();
	ss << "Posicion:" << Posicion;
	if (miDragon) {
		ss << miDragon->to_string();
	}
	return ss.str();
}

cVikingo::~cVikingo() {}
