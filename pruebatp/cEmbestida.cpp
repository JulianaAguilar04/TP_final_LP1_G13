#include "cEmbestida.h"

cEmbestida* cEmbestida::AltaDragon()
{
    string nombre, caracteristica, tamano, color;
    int resistencia = 0, hab = 0, clase = 0, velocidad = 0, agilidad = 0, fuerza;
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
    cout << "Ingrese  la velocidad del dragon:" << endl;
    cin >> velocidad;
    cout << "Ingrese la agilidad del dragon:" << endl;
    cin >> agilidad;
    cout << "Ingrese la fuerza de impacto del dragon:" << endl;
    cin >> fuerza;
    cout << "HABILIDADES (ingrese cantidad) :" << endl;
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

    return new cEmbestida(nombre, caracteristica, tamano, color, estado, resistencia, velocidad, agilidad, fuerza, v_habilidades, ataque);
}

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
