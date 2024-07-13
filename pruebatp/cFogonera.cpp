#include "cFogonera.h"

cFogonera* cFogonera::AltaDragon()
{
    string nombre, caracteristica, tamano, color;
    int resistencia = 0, hab = 0, clase = 0, presicion = 0, rescalor=0;
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
    cout << "Ingrese la presicion del dragon:" << endl;
    cin >> presicion;
    cout << "Ingrese la resistencia al calor del dragon:" << endl;
    cin >> rescalor;
    cout << "HABILIDADES (ingrese cantidad):" << endl;
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
    cout << "Ingrese el da�o del ataque del dragon: ";
    cin >> danioAtaque;
    cout << "Ingrese el alcance del ataque del dragon: ";
    cin >> alcanceAtaque;
    cAtaque* ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);
   

    return new cFogonera(nombre, caracteristica, tamano, color, estado, resistencia, presicion, rescalor, v_habilidades, ataque);
}


void cFogonera::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
    double efectividad = jinete.getEfectividad();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Control de fuego") {
        precision += incremento;
        cout << Nombre << "ha mejorado su precision en: " << incremento << ". Su presicion ahora es de:" << precision << endl;
    }
    else if (tipoEntrenamiento == "Resistencia al calor") {
        resistenciaAlCalor += incremento;
        cout << Nombre << "ha mejorado su resistencia al calor en:" << incremento << ". Su resistencia ahora es de:" << resistenciaAlCalor << endl;
    }
    //aca va lo de habilidades
    if (Estado) {
        DesarrollarEstrategia("Ataque");
        DesarrollarEstrategia("Defensa");
    }
    NivelEntrenamiento++;
}

/*
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
*/

void cFogonera::DesarrollarEstrategia(const string& tipo)
{
    if (tipo == "Ataque") { //hago random que estrategia desarrolla
        string nuevaEstrategia = "Estrategia de ataque:" + std::to_string(EstrategiasAtaque.size()+1);
        EstrategiasAtaque.push_back(nuevaEstrategia);
        cout << Nombre << "ha desarrollado una nueva estrategia de ataque:" << nuevaEstrategia << endl;
    }
    else if (tipo == "Defensa") {
        string nuevaEstrategia = "Estrategia de defensa:" + std::to_string(EstrategiasDefensa.size() + 1);
        EstrategiasDefensa.push_back(nuevaEstrategia);
        cout << Nombre << "ha desarrollado una nueva estrategia de defensa:" << nuevaEstrategia << endl;
    }
}

cFogonera::~cFogonera()
{
}

/*
if (tipo == "Ataque") {
        string nuevaEstrategia = "Estrategia de ataque " + std::to_string(EstrategiasAtaque.size() + 1);
        EstrategiasAtaque.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de ataque: " << nuevaEstrategia << endl;
    } else if (tipo == "Defensa") {
        string nuevaEstrategia = "Estrategia de defensa " + std::to_string(EstrategiasDefensa.size() + 1);
        EstrategiasDefensa.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de defensa: " << nuevaEstrategia << endl;
    }
*/