#include "cJinete.h"

//constructor por parametros
cJinete::cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, cDragon* miDragon) {
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Apodo = Apodo;
    this->FecNac = FecNac;
    this->Caracteristicas = Caracteristicas;
    this->miDragon = miDragon;
}

cJinete::~cJinete() {
}

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


/* ESTO ES LO QUE HABIAS HECHO VOS ANTES JULI, LO DEJE ACA POR LAS DUDAS JE :)

#include "cJinete.h"

cJinete::cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, cDragon* miDragon)
{
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Apodo = Apodo;
    this->FecNac = FecNac;
    this->Caracteristicas = Caracteristicas;
    this->miDragon = miDragon;
}

cJinete::~cJinete()
{
}

string cJinete::getNombre()
{
    return this->Nombre;
}

string cJinete::getApellido()
{
    return this->Apellido;
}

string cJinete::getApodo()
{
    return this->Apodo;
}

string cJinete::getFecNac()
{
    return this->getFecNac;
}

string cJinete::getCaracteristicas()
{
    return this->Caracteristicas;
}

void cJinete::IncorporarDragon()
{
}
 */

