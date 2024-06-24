#include "cDragon.h"
#include "cJinete.h"

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
int cDragon::getResistencia()
{
    return Resistencia;
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

void cDragon::Baja(vector<cDragon*>& Dragones_isla)
{
    //necesito especificamente el dragon que se quiere sacar de la lista
}

/*void cDragon::AltaDragon(cDragon* dragon)
{

}*/

void cDragon::Entrenar(const string &tipoEntrenamiento, const cJinete& Jinete)
{
    double efectividad = Jinete.getEfectividad();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Velocidad") {
        Velocidad += incremento;
        cout << Nombre << " ha mejorado su velocidad en " << incremento << ". Nueva velocidad: " << Velocidad << endl;
    }
    else if (tipoEntrenamiento == "Resistencia") {
        Resistencia += incremento; 
        cout << Nombre << " ha mejorado su resistencia en " << incremento << ". Nueva resistencia: " << Resistencia << endl;
    }
    else if (tipoEntrenamiento == "Habilidades") {
        string nuevaHabilidad = "Habilidad avanzada " + std::to_string(NivelEntrenamiento);
        Habilidades.push_back(nuevaHabilidad);
        cout << Nombre << " ha aprendido una nueva habilidad: " << nuevaHabilidad << endl;
    }
    else {
        cout << "Tipo de entrenamiento no reconocido. Por favor, elige entre 'Velocidad', 'Resistencia' o 'Habilidades'." << endl;
    }
    
    if (Estado) {
        DesarrollarEstrategia("Ataque");
        DesarrollarEstrategia("Defensa");
    }
    
    NivelEntrenamiento++;
}

void cDragon::DesarrollarEstrategia(const string& tipo) {
    if (tipo == "Ataque") {
        string nuevaEstrategia = "Estrategia de ataque " + std::to_string(EstrategiasAtaque.size() + 1);
        EstrategiasAtaque.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de ataque: " << nuevaEstrategia << endl;
    } else if (tipo == "Defensa") {
        string nuevaEstrategia = "Estrategia de defensa " + std::to_string(EstrategiasDefensa.size() + 1);
        EstrategiasDefensa.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de defensa: " << nuevaEstrategia << endl;
    }
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
