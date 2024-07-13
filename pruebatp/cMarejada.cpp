#include "cMarejada.h"

cMarejada* cMarejada::AltaDragon()
{
    string nombre, caracteristica, tamano, color;
    int resistencia = 0, hab = 0, clase = 0, adaptabilidad=0;
    bool estado;
    char domado;
    vector<string> v_habilidades;

    cout << "Ingrese el nombre del dragon: ";
    cin >> nombre;
    cout << "Ingrese las caracteristicas del dragon: ";
    cin >> caracteristica;
    cout << "Ingrese el tamano del dragon: ";
    cin >> tamano;
    cout << "Ingrese el color del dragon: ";
    cin >> color;
    cout << "El dragon esta domado? (s/n): ";
    cin >> domado;
    estado = (domado == 's' || domado == 'S');
    cout << "Ingrese la resistencia del dragon:" << endl;
    cin >> resistencia;
    cout << "Ingrese el nivel de adaptabilidad del dragon:" << endl;
    cin >> adaptabilidad;
    cout << "HABILIDADES (ingrese cantidad): " << endl;
    cin >> hab;

    v_habilidades.reserve(hab); //reservo espacio para la cantidades de habilidades
    for (int i = 0; i < hab; i++)
    {
        string habilidad;
        cout << "Ingrese habilidad:" << (i + 1) << ":" << endl;
        cin >> habilidad;
        v_habilidades.push_back(habilidad);
    }

    string tipoAtaque, danioAtaque, alcanceAtaque;
    cout << "Ingrese el tipo de ataque del dragon: ";
    cin >> tipoAtaque;
    cout << "Ingrese el daño del ataque del dragon: ";
    cin >> danioAtaque;
    cout << "Ingrese el alcance del ataque del dragon: ";
    cin >> alcanceAtaque;
    cAtaque* ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);

    return new cMarejada(nombre, caracteristica, tamano, color, estado, resistencia, adaptabilidad, v_habilidades, ataque);
}

void cMarejada::Entrenar(const string tipoEntrenamiento, const cJinete& jinete) {
    double efectividad = jinete.getEfectividad();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Diferentes terrenos") {
        adaptabilidad += incremento;
        cout << Nombre << "ha mejorado su adaptabilidad en: " << incremento << ". Su adaptabilidad ahora es de:" << adaptabilidad << endl;
    }
    if (Estado) {
        DesarrollarEstrategia("Ataque");
        DesarrollarEstrategia("Defensa");
    }
    NivelEntrenamiento++;
}

void cMarejada::DesarrollarEstrategia(const string& tipo)
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

cMarejada::~cMarejada()
{
}

