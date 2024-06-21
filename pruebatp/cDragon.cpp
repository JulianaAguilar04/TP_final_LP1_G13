#include "cDragon.h"
#include "cJinete.h"

//constructor por parametro
cDragon::cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Resistencia, vector <string> &Habilidades, cAtaque* miAtaque):NivelEntrenamiento(1)
{
    this->Nombre = Nombre;
    this->Caracteristica = Caracteristica;
    this->Tamano = Tamano;
    this->Color = Color;
    this->Estado = Estado;
    this->Velocidad = Velocidad;
    this->Resistencia = Resistencia;
    this->Habilidades = Habilidades;
    this->FormadeAtaque = miAtaque;
}
//constructor por copia-parametro
cDragon::cDragon(cDragon& Dragoncito)
{
    this->Nombre = Dragoncito.Nombre;
    this->Caracteristica = Dragoncito.Caracteristica;
    this->Tamano = Dragoncito.Tamano;
    this->Color = Dragoncito.Color;
    this->Estado = Dragoncito.Estado;
    this->Velocidad = Dragoncito.Velocidad;
    this->Resistencia = Dragoncito.Resistencia;
    this->Habilidades = Dragoncito.Habilidades;
    this->NivelEntrenamiento = Dragoncito.NivelEntrenamiento;
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

void cDragon::Baja(vector<cDragon>& Dragones_isla)
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
        std::cout << Nombre << " ha mejorado su velocidad en " << incremento << ". Nueva velocidad: " << Velocidad << std::endl;
    }
    else if (tipoEntrenamiento == "Resistencia") {
        Resistencia += incremento; 
        std::cout << Nombre << " ha mejorado su resistencia en " << incremento << ". Nueva resistencia: " << Resistencia << std::endl;
    }
    else if (tipoEntrenamiento == "Habilidades") {
        std::string nuevaHabilidad = "Habilidad avanzada " + std::to_string(NivelEntrenamiento);
        Habilidades.push_back(nuevaHabilidad);
        std::cout << Nombre << " ha aprendido una nueva habilidad: " << nuevaHabilidad << std::endl;
    }
    else {
        std::cout << "Tipo de entrenamiento no reconocido. Por favor, elige entre 'Velocidad', 'Resistencia' o 'Habilidades'." << std::endl;
    }
    NivelEntrenamiento++;
}

void cDragon::mostrarHabilidades()
{
    cout << "Habilidades de " << Nombre << ": ";
    for (const auto& habilidad : Habilidades) {
        std::cout << habilidad << " ";
    }
    cout << endl;
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
