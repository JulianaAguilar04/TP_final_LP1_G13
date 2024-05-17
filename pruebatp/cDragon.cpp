#include "cDragon.h"

//constructor por parametro y por defecto
cDragon::cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, cAtaque* miAtaque)
{
    this->Nombre = Nombre;
    this->Caracteristica = Caracteristica;
    this->Tamano = Tamano;
    this->Color = Color;
    this->Estado = Estado;
    FormadeAtaque = miAtaque;
}
string cDragon::getNombre()
{
    return Nombre;
}
string cDragon::getCaracteristica()
{
    return Caracteristica;
}
string cDragon::getTamano()
{
    return Tamano;
}
string cDragon::getColor()
{
    return Color;
}
bool cDragon::getEstado()
{
    return Estado;
}
void cDragon::setNombre(string nuevoNombre)
{
    Nombre = nuevoNombre;
}
void cDragon::setCaracteristica(string nuevaCaracteristica)
{
    Caracteristica = nuevaCaracteristica;
}
void cDragon::setTamano(string nuevoTamano)
{
    Tamano = nuevoTamano;
}
void cDragon::setColor(string nuevoColor)
{
    Color = nuevoColor;
}
void cDragon::setEstado(bool nuevoEstado)
{
    Estado = nuevoEstado;
}
string cDragon::AltaNombre(string Nombre)
{
    return string();
}

bool cDragon::Domado()
{
    return false;
}

string cDragon::to_string()
{
    stringstream ss;
    ss << "-Nombre del dragon:" << Nombre << endl;
    ss << "-Caracteristicas:" << Caracteristica << endl;
    ss << "-Tamanio:" << Tamano << endl;
    ss << "-Color:" << Color << endl;
    ss << "-Estado:" << Estado << endl;
    ss << "-Ataque:\n" << FormadeAtaque->to_string() << endl;
    return ss.str();
}

cDragon::~cDragon()
{
}
