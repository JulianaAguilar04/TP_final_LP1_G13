#include "cMarejada.h"

void cMarejada::EntrenarMarejada(string tipoEntrenamiento, cJinete& jinete)
{
    double efectividad = jinete.getEfectividad();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Diferentes terrenos") {
        adaptabilidad += incremento;
        cout << Nombre << "ha mejorado su adaptabilidad en: " << incremento << ". Su adaptabilidad ahora es de:" << adaptabilidad << endl;
    }
    if (Estado) {
        DesarrollarEstrategiaMarejada("Ataque");
        DesarrollarEstrategiaMarejada("Defensa");
    }
    NivelEntrenamiento++;
}

void cMarejada::DesarrollarEstrategiaMarejada(const string& tipo)
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

