#include "cJinete.h"

//constructor por parametros
cJinete::cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, double Efectividad):cPersona (Nombre, Apellido, Apodo, FecNac)
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

double cJinete::getEfectividad() const
{
    return Efectividad;
}

void cJinete::IncorporarDragon() {
    
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