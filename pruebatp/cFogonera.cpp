#include "cFogonera.h"

string cFogonera::EstrategiaAtaque(int opcion)
{
    switch (opcion)
    {
    case 1: return "Lanzallamas";
    case 2: return "Explosion de fuego";
    case 3: return "Rayo de fuego";
    default: return "Estrategia desconocida";
    }
}

string cFogonera::EstrategiaDefensa(int opcion)
{
    switch (opcion)
    {
    case 1: return "Escudo de fuego";
    case 2: return "Niebla de humo";
    case 3: return "Regeneracion por calor";
    default: return "Estrategia desconocida";
    }
}

cFogonera* cFogonera::AltaDragon()
{
    string nombre, caracteristica, tamano, color;
    int resistencia = 0, hab = 0, clase = 0, presicion = 0, rescalor=0;
    bool estado = false;
    vector<string> v_habilidades;
    cAtaque* ataque = nullptr;

    try {
        cout << "Ingrese el nombre del dragon: ";
        cin >> nombre;
        cout << "Ingrese las caracteristicas del dragon: ";
        cin >> caracteristica;
        cout << "Ingrese el tamano del dragon: ";
        cin >> tamano;
        cout << "Ingrese el color del dragon: ";
        cin >> color;
        cout << "Ingrese la resistencia del dragon:" << endl;
        cin >> resistencia;
        if (resistencia <= -1)
            throw invalid_argument("La resistencia debe ser mayor a 0");
        cout << "Ingrese la presicion del dragon:" << endl;
        cin >> presicion;
        if (presicion <= -1)
            throw invalid_argument("Respuesta invalida para presicion");
        cout << "Ingrese la resistencia al calor del dragon:" << endl;
        cin >> rescalor;
        if (rescalor <= -1)
            throw invalid_argument("Respuesta invalida para resistencia al calor");
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
        cout << "Ingrese el daño del ataque del dragon: ";
        cin >> danioAtaque;
        cout << "Ingrese el alcance del ataque del dragon: ";
        cin >> alcanceAtaque;

        ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);
    }
    catch (const invalid_argument& e) {
        cout << "Error:" << e.what() << endl;
        delete ataque;
    }
    catch (const exception& e) {
        cout << "Error:" << e.what() << endl;
        delete ataque;
    }

    return new cFogonera(nombre, caracteristica, tamano, color, estado, resistencia, presicion, rescalor, v_habilidades, ataque);
}


void cFogonera::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
    int efectividad = jinete.getResultado();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Control de fuego") {
        precision += incremento;
        cout << Nombre << " ha mejorado su precision en: " << incremento << ". Su presicion ahora es de:" << precision << endl;
    }
    else if (tipoEntrenamiento == "Resistencia al calor") {
        resistenciaAlCalor += incremento;
        cout << Nombre << " ha mejorado su resistencia al calor en:" << incremento << ". Su resistencia ahora es de:" << resistenciaAlCalor << endl;
    }
    
    if (Estado) {
        DesarrollarEstrategia("Ataque");
        DesarrollarEstrategia("Defensa");
    }
    NivelEntrenamiento++;
}

void cFogonera::DesarrollarEstrategia(const string& tipo)
{
    try {
        if (tipo != "Ataque" && tipo != "Defensa") {
            throw invalid_argument("El tipo de estrategia no es valida!");
        }
        if (tipo == "Ataque") { //hago random que estrategia desarrolla
            string nuevaEstrategia;
            bool existe = false;

            do {
                int randomNum = rand() % 3 + 1;
                nuevaEstrategia = EstrategiaAtaque(randomNum);

                existe = false;
                for (string& estrategia : EstrategiasAtaque) {
                    if (estrategia == nuevaEstrategia) {
                        existe = true;
                        break;
                    }
                }
            } while (existe);

            EstrategiasAtaque.push_back(nuevaEstrategia);
            cout << Nombre << " ha desarrollado una nueva estrategia de ataque:" << nuevaEstrategia << endl;
        }
        else if (tipo == "Defensa") {
            string nuevaEstrategia;
            bool existe = false;

            do {
                int randomNum = rand() % 3 + 1;
                nuevaEstrategia = EstrategiaDefensa(randomNum);

                existe = false;
                for (string& estrategia : EstrategiasDefensa) {
                    if (estrategia == nuevaEstrategia) {
                        existe = true;
                        break;
                    }
                }
            } while (existe);

            EstrategiasDefensa.push_back(nuevaEstrategia);
            cout << Nombre << " ha desarrollado una nueva estrategia de defensa:" << nuevaEstrategia << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error:" << e.what() << endl;
    }
    /*if (tipo == "Ataque") { //hago random que estrategia desarrolla
        int randomNum = rand() % 3 + 1;
        string nuevaEstrategia = EstrategiaAtaque(randomNum);
        EstrategiasAtaque.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de ataque:" << nuevaEstrategia << endl;
    }
    else if (tipo == "Defensa") {
        int randomNum = rand() % 3 + 1;
        string nuevaEstrategia = EstrategiaDefensa(randomNum);
        EstrategiasDefensa.push_back(nuevaEstrategia);
        cout << Nombre << " ha desarrollado una nueva estrategia de defensa:" << nuevaEstrategia << endl;
    }*/
}

void cFogonera::print(ostream& os)
{
    cDragon::print(os);
    os << "Presicion:" << precision << endl;
    os << "Resistencia al calor:" << resistenciaAlCalor << endl;
}

cFogonera::~cFogonera()
{
}