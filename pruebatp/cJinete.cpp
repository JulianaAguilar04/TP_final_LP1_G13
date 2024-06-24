#include "cJinete.h"

//constructor por parametros
cJinete::cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, double Efectividad, int Fuerza):cPersona (Nombre, Apellido, Apodo, FecNac, Fuerza)
{
    this->Caracteristicas = Caracteristicas;
    this->Efectividad = Efectividad;
}

string cJinete::to_string()
{
    stringstream ss;
    ss << cPersona::to_string();
    ss << "Caracteristicas:" << Caracteristicas << endl;
    return ss.str();
}

void cJinete::mostrarDragones() const
{
    cout << "El jinete:" << Nombre << "tiene estos dragones:" << endl;
    for (const auto& dragon : misDragones) {
        cout << "-" << dragon->getNombre() << endl;
    }
}

void cJinete::mostrarInfo(ostream& os) const
{
    os << "Nombre:" << Nombre << endl;
    os << "Apellido: " << Apellido << endl;
    os << "Apodo:" << Apodo << endl;
    os << "Fecha de nacimiento:" << FecNac << endl;
    os << "Caracteristicas:" << Caracteristicas << endl;
    os << "Efectividad:" << Efectividad << endl;
    os << "Fuerza:" << Fuerza << endl;
    os << "Dragones:" << endl;
    for (const auto& dragon : misDragones) {
        os << "- " << dragon->to_string() << std::endl;
    }
}

ostream& operator<<(ostream& os, const cJinete& j)
{
    j.mostrarInfo(os);
    return os;
}

double cJinete::getEfectividad() const
{
    return Efectividad;
}

vector<cDragon*> cJinete::getMisDragones()
{
    return misDragones;
}

void cJinete::IncorporarDragon(cDragon* dragon) {
    misDragones.push_back(dragon);
}

cJinete::~cJinete() {
}

/*
string cJinete::getNombre() {
    return Nombre;
}

string cJinete::getApellido() {
    return Apellido;
}

string cJinete::getApodo() {
    return Apodo;
}


string cJinete::getFecNac() {
    return FecNac; //esta mal estoy segura 
}


string cJinete::getCaracteristicas() {
    return Caracteristicas;
}

void cJinete::setNombre(string nuevoNombre) {
    Nombre = nuevoNombre;
}

void cJinete::setApellido(string nuevoApellido) {
    Apellido = nuevoApellido;
}

void cJinete::setApodo(string nuevoApodo) {
    Apodo = nuevoApodo;
}

void cJinete::setCaracteristicas(string nuevasCaracteristicas) {
    Caracteristicas = nuevasCaracteristicas;
}

void cJinete::setFecNac(string nuevaFecNac) {
    FecNac = nuevaFecNac;
}

string cJinete::to_string()
{
    stringstream ss;
    ss << "-Nombre:" << Nombre << endl;
    ss << "-Apellido:" << Apellido << endl;
    ss << "-Apodo:" << Apodo << endl;
    ss << "-Fecha de nacimiento:" << FecNac << endl;
    ss << "-Caracteristicas:" << Caracteristicas << endl;
    ss << miDragon->to_string() << endl;

    return ss.str();
}
*/


