#include "cDragon.h"

//constructor por parametro
cDragon::cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, cAtaque* miAtaque)
{
    this->Nombre = Nombre;
    this->Caracteristica = Caracteristica;
    this->Tamano = Tamano;
    this->Color = Color;
    this->Estado = Estado;
    FormadeAtaque = miAtaque;
}
//constructor por copia-parametro
cDragon::cDragon(cDragon& Dragoncito)
{
    this->Nombre = Dragoncito.Nombre;
    this->Caracteristica = Dragoncito.Caracteristica;
    this->Tamano = Dragoncito.Tamano;
    this->Color = Dragoncito.Color;
    this->Estado = Dragoncito.Estado;
    FormadeAtaque = Dragoncito.FormadeAtaque;
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
void cDragon::AltaNombre(string Nombre)
{
    ;
}

bool cDragon::Domado()
{
    return false;
}

string cDragon::to_string()
{
    stringstream ss;
    ss << "\n-Nombre del dragon:" << Nombre << endl;
    ss << "-Caracteristicas:" << Caracteristica << endl;
    ss << "-Tamanio:" << Tamano << endl;
    ss << "-Color:" << Color << endl;
    ss << "-Estado:" << Estado << endl;
    ss << "-Ataque:\n" << FormadeAtaque->to_string() << endl;
    return ss.str();
}

void cDragon::Baja(vector<cDragon>& Dragones_isla)
{
    //necesito especificamente el dragon que se quiere sacar de la lista
}

/*void cDragon::AltaDragon(cDragon* dragon)
{

}*/

void cDragon::Entrenar()
{

}

ostream& operator<<(ostream& s, cDragon& d)
{
    s << "Nombre del dragón:" << d.Nombre << endl;
    s << "Caracteristicas:" << d.Caracteristica << endl;
    s << "Tamanio:" << d.Tamano << endl;
    s << "Color: " << d.Color << endl;
    s << "Estado: " << ((d.Estado == false) ? "No domado" : "Domado") << endl;
    s << "Ataque: " << *(d.FormadeAtaque)<<endl;
    return s;
}

cDragon::~cDragon()
{
}
