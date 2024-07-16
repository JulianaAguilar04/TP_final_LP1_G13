#include "cJinete.h"

string cJinete::to_string() {
    stringstream ss;
    ss << cPersona::to_string();
    ss << "Caracteristicas: " << Caracteristicas << endl;
    ss << "Resultado: " << ResulEntrenamientostring(Resultado) << endl;
    ss << "Numero de Ovejas: " << numeroOvejas << endl;
    return ss.str();
}

void cJinete::mostrarDragones() const {
    cout << "El jinete " << Nombre << " tiene estos dragones:" << endl;
    for (const auto& dragon : misDragones) {
        cout << "-" << dragon->getNombre() << endl;
    }
}

void cJinete::mostrarInfo(ostream& os) const {
    os << "Nombre: " << Nombre << endl;
    os << "Apellido: " << Apellido << endl;
    os << "Apodo: " << Apodo << endl;
    os << "Fecha de nacimiento: " << FecNac << endl;
    os << "Caracteristicas: " << Caracteristicas << endl;
    os << "Resultado: " << ResulEntrenamientostring(Resultado) << endl;
    os << "Fuerza: " << Fuerza << endl;
    os << "Dragones:" << endl;
    for (const auto& dragon : misDragones) {
        os << "- " << dragon->to_string() << endl;
    }
}

ostream& operator<<(ostream& os, const cJinete& j) {
    j.mostrarInfo(os);
    return os;
}

bool cJinete::tieneDragon(cDragon* dragon) {
    for (cDragon* d : misDragones) {
        if (d == dragon) {
            return true;
        }
    }
    return false;
}

string cJinete::getNombre() const {
    return Nombre;
}

ResulEntrenamiento cJinete::getResultado() const {
    return Resultado;
}

vector<cDragon*> cJinete::getMisDragones() {
    return misDragones;
}

void cJinete::IncorporarDragon(cDragon* dragon) {
    misDragones.push_back(dragon);
}

int cJinete::getNumeroOvejas() const {
    return numeroOvejas;
}

cJinete& cJinete::operator+=(int ovejas) {
    numeroOvejas += ovejas;
    return *this;
}

cJinete::~cJinete() {
}

/*#include "cJinete.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string cJinete::to_string() {
    stringstream ss;
    ss << cPersona::to_string();
    ss << "Caracteristicas: " << Caracteristicas << endl;
    return ss.str();
}

void cJinete::mostrarDragones() const {
    cout << "El jinete: " << Nombre << " tiene estos dragones:" << endl;
    for (const auto& dragon : misDragones) {
        cout << "-" << dragon->getNombre() << endl;
    }
}

void cJinete::mostrarInfo(ostream& os) const {
    os << "Nombre: " << Nombre << endl;
    os << "Apellido: " << Apellido << endl;
    os << "Apodo: " << Apodo << endl;
    os << "Fecha de nacimiento: " << FecNac << endl;
    os << "Caracteristicas: " << Caracteristicas << endl;
    os << "Resultado de entrenaminto: " << ResulEntrenamientostring(Resultado) << endl;
    os << "Fuerza: " << Fuerza << endl;
    os << "Dragones:" << endl;
    for (const auto& dragon : misDragones) {
        os << "- " << dragon->to_string() << std::endl;
    }
}

ostream& operator<<(ostream& os, const cJinete& j) {
    j.mostrarInfo(os);
    return os;
}

bool cJinete::tieneDragon(cDragon* dragon) {
    for (cDragon* d : misDragones) {
        if (d == dragon) {
            return true;
        }
    }
    return false;
}

string cJinete::getNombre() const {
    return Nombre;
}

ResulEntrenamiento cJinete::getResultado() const
{
    return Resultado;
}

vector<cDragon*> cJinete::getMisDragones() {
    return misDragones;
}

void cJinete::IncorporarDragon(cDragon* dragon) {
    misDragones.push_back(dragon);
}

int cJinete::getNumeroOvejas() const {
    return numeroOvejas;
}

cJinete& cJinete::operator+=(int ovejas) {
    numeroOvejas += ovejas;
    return *this;
}

cJinete::~cJinete() {
}
*/

/*
LO COMENTO PARA PONERLO MAS LIMPIO Y VER QUE FALLA (15/07  15hs) 

#include "cJinete.h"

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

bool cJinete::tieneDragon(cDragon* dragon)
{
    for (cDragon* d : misDragones) {
        if (d == dragon) {
            return true;
        }
    }
    return false;
}

string cJinete::getNombre() const
{
    return string();
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

void cJinete::incrementarOvejas(int cantidad) {
    numeroOvejas += cantidad;
}

int cJinete::getNumeroOvejas() const {
    return numeroOvejas;
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


