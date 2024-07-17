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
    return Estado;
}

string cDragon::to_string()
{
    stringstream ss;
    ss << "Nombre del dragon: " << Nombre << endl;
    ss << "Caracteristicas: " << Caracteristica << endl;
    ss << "Tamanio: " << Tamano << endl;
    ss << "Color: " << Color << endl;
    ss << "Estado: " << (Estado ? "Domado" : "No domado") << endl;
    ss << "Resistencia: " << Resistencia << endl;
    ss << "Habilidades:" << endl;
    if (Habilidades.empty()) {
        ss << "- Ninguna" << endl;
    }
    else {
        for (const auto& habilidad : Habilidades) {
            ss << "- " << habilidad << endl;
        }
    }
    ss << "Estrategias de ataque:" << endl;
    if (EstrategiasAtaque.empty()) {
        ss << "- Ninguna" << endl;
    }
    else {
        for (const auto& ataque : EstrategiasAtaque) {
            ss << "- " << ataque << endl;
        }
    }
    ss << "Estrategias de defensa:" << endl;
    if (EstrategiasDefensa.empty()) {
        ss << "- Ninguna" << endl;
    }
    else {
        for (const auto& defensa : EstrategiasDefensa) {
            ss << "- " << defensa << endl;
        }
    }
    ss << " ------------------------------" << endl;
    return ss.str();
}

void cDragon::print(ostream& os)
{
    os << to_string();
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
        delete* it;
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
