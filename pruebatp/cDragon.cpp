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

void cDragon::print(ostream& os)
{
    os << "Nombre del dragon:" << Nombre << endl;
    os << "Caracteristicas:" << Caracteristica << endl;
    os << "Tamanio:" << Tamano << endl;
    os << "Color: " << Color << endl;
    os << "Estado: " << ((Estado == false) ? "No domado" : "Domado") << endl;
    os << "Resistencia:" << Resistencia << endl;
    if (FormadeAtaque) {
        os << "Ataque:" << (FormadeAtaque->to_string()) << endl;
    }
    else {
        os << "No hay forma de ataque asignado" << endl;
    }
    os << "Habilidades:" << endl;
    for (const auto& habilidad : Habilidades) {
        os << "-" << habilidad << endl;
    }
    os << "Estrategias de ataque:" << endl;
    for (const auto& ataque : EstrategiasAtaque) {
        os << "-" << ataque << endl;
    }
    os << "Estrategias de defensa:" << endl;
    for (const auto& defensa : EstrategiasDefensa) {
        os << defensa << endl;
    }

    os << endl;
}

void cDragon::DesarrollarEstrategia(const string& tipo)
{
}

void cDragon::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
}

void cDragon::Baja(vector<cDragon*>& Dragones_isla)
{
    auto it = find(Dragones_isla.begin(), Dragones_isla.end(), this);
    if (it != Dragones_isla.end()) {
        // Liberar memoria del dragón si es necesario
        delete* it;
        // Eliminar el dragón de la lista
        Dragones_isla.erase(it);
    }
}


void cDragon::mostrarHabilidades()
{
    cout << "Habilidades de " << Nombre << ": ";
    for (const auto& habilidad : Habilidades) {
        cout << habilidad << endl;
        cout << endl;
    }
    cout << endl;
}


ostream& operator<<(ostream& os, cDragon& d)
{
    d.print(os);
    return os;
}

cDragon::~cDragon()
{
}
