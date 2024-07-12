#include "cEmbestida.h"

void cEmbestida::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
    double efectividad = jinete.getEfectividad();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Carrera de velocidad") {
        velocidad += incremento;
        cout << Nombre << "ha mejorado su velocidad en: " << incremento << ". Su velocidad ahora es de:" << velocidad << endl;
    }
    else if (tipoEntrenamiento == "Obstaculos") {
        agilidad += incremento;
        cout << Nombre << "ha mejorado su agilidad en:" << incremento << ". Su agilidad ahora es de:" << agilidad << endl;
    }
    else if (tipoEntrenamiento == "Fuerza de impacto") {
        fuerzaImpacto += incremento;
        cout << Nombre << "ha mejorado su resistencia en:" << incremento << ". Su resistencia ahora es de:" << fuerzaImpacto << endl;
    }
    //aca va lo de habilidades
    if (Estado) {
        DesarrollarEstrategia("Ataque");
        DesarrollarEstrategia("Defensa");
    }
    NivelEntrenamiento++;
}

void cEmbestida::DesarrollarEstrategia(const string& tipo)
{
    if (tipo == "Ataque") { //hago random que estrategia desarrolla
        string nuevaEstrategia = "Estrategia de ataque:" + std::to_string(EstrategiasAtaque.size() + 1);
        EstrategiasAtaque.push_back(nuevaEstrategia);
        cout << Nombre << "ha desarrollado una nueva estrategia de ataque:" << nuevaEstrategia << endl;
    }
    else if (tipo == "Defensa") {
        string nuevaEstrategia = "Estrategia de defensa:" + std::to_string(EstrategiasDefensa.size() + 1);
        EstrategiasDefensa.push_back(nuevaEstrategia);
        cout << Nombre << "ha desarrollado una nueva estrategia de defensa:" << nuevaEstrategia << endl;
    }
}

cEmbestida::~cEmbestida()
{
}
