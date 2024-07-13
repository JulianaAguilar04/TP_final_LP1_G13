#include "cDragon.h"
#include "cJinete.h"

string cDragon::getNombre() const
{
    return Nombre;
}
string cDragon::getCaracteristica() const
{
    return Caracteristica;
}
string cDragon::getTamano() const
{
    return Tamano;
}
string cDragon::getColor() const
{
    return Color;
}
int cDragon::getResistencia() const
{
   return Resistencia;
}
bool cDragon::getEstado() const
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
void cDragon::AltaNombre(string nuevoNombre)
{
    Nombre = nuevoNombre;
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
    ss << "-Estado:" << ((Estado == false) ? "No esta domado" : "Esta domado") << endl;
    ss << "-Ataque:\n" << FormadeAtaque->to_string() << endl;
    return ss.str();
}

void cDragon::DesarrollarEstrategia(const string& tipo)
{
}

/*
cDragon* cDragon::AltaDragon()
{
}
*/

void cDragon::Baja(vector<cDragon*>& Dragones_isla)
{
    //necesito especificamente el dragon que se quiere sacar de la lista
}


void cDragon::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
}

void cDragon::mostrarHabilidades()
{
    cout << "Habilidades de " << Nombre << ": ";
    for (const auto& habilidad : Habilidades) {
        cout << habilidad << " ";
    }
    cout << endl;
}


ostream& operator<<(ostream& s, cDragon& d)
{
    s << "Nombre del dragon:" << d.Nombre << endl;
    s << "Caracteristicas:" << d.Caracteristica << endl;
    s << "Tamanio:" << d.Tamano << endl;
    s << "Color: " << d.Color << endl;
    s << "Estado: " << ((d.Estado == false) ? "No domado" : "Domado") << endl;
    if (d.FormadeAtaque) {
        s << "Ataque: \n" << (d.FormadeAtaque->to_string()) << endl;
    }
    else {
        s << "No hay forma de ataque asiignado" << endl;
    }
    s << "Habilidades:" << endl;
    for (const auto& habilidad : d.Habilidades) {
        s << habilidad << " ";
    }
    s << endl;
    return s;
}

cDragon::~cDragon()
{
}
