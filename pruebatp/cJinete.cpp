#include "cJinete.h"

//constructor por parametros
cJinete::cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, cDragon* miDragon):cPersona (Nombre, Apellido, Apodo, FecNac)
{
    this->Caracteristicas = Caracteristicas;
    this->miDragon = miDragon;
}

string cJinete::to_string()
{
    cPersona::to_string();
    stringstream ss;
    ss << "Caracteristicas:" << Caracteristicas << endl;
    ss << miDragon->to_string();
    return ss.str();
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

void cJinete::IncorporarDragon() {
    // completar jaja 
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