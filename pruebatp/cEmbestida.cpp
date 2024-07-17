#include "cEmbestida.h"

string cEmbestida::EstrategiaAtaque(int opcion)
{
    switch (opcion)
    {
    case 1: return "Embestir a gran velocidad";
    case 2: return "Rafaga de ataque con sus cuernos";
    case 3: return "Golpe sismico";
    default: return "Estrategia desconocida";
    }
}

string cEmbestida::EstrategiaDefensa(int opcion)
{
    switch (opcion)
    {
    case 1: return "Escudo";
    case 2: return "Disparo de espinas";
    case 3: return "Camuflaje terrestre";
    default: return "Estrategia desconocida";
    }
}

cEmbestida* cEmbestida::AltaDragon()
{
    string nombre, caracteristica, tamano, color;
    int resistencia = 0, hab = 0, clase = 0, velocidad = 0, agilidad = 0, fuerza;
    bool estado;
    char domado;
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
        cout << "El dragon esta domado? (s/n): ";
        cin >> domado;
        if (domado != 's' && domado != 'S' && domado != 'n' && domado != 'N')
            throw invalid_argument("Respuesta invalida para domado");
        estado = (domado == 's' || domado == 'S');
        cout << "Ingrese la resistencia del dragon:" << endl;
        cin >> resistencia;
        if(resistencia<= -1)
            throw invalid_argument("Respuesta invalida para resistencia");
        cout << "Ingrese  la velocidad del dragon:" << endl;
        cin >> velocidad;
        if(velocidad <= -1)
            throw invalid_argument("Respuesta invalida para velocidad");
        cout << "Ingrese la agilidad del dragon:" << endl;
        cin >> agilidad;
        if(agilidad<=-1)
            throw invalid_argument("Respuesta invalida para agilidad");
        cout << "Ingrese la fuerza de impacto del dragon:" << endl;
        cin >> fuerza;
        if(fuerza<=-1)
            throw invalid_argument("Respuesta invalida para fuerza");
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

    return new cEmbestida(nombre, caracteristica, tamano, color, estado, resistencia, velocidad, agilidad, fuerza, v_habilidades, ataque);
}

void cEmbestida::print(ostream& os)
{
    cDragon::print(os);
    os << "Velocidad:" << velocidad << endl;
    os << "Agilidad:" << agilidad << endl;
    os << "Fuerza de impacto:" << fuerzaImpacto;
}

void cEmbestida::Entrenar(const string tipoEntrenamiento, const cJinete& jinete)
{
    int efectividad = jinete.getResultado();
    int incremento = static_cast<int>(efectividad * NivelEntrenamiento);

    if (tipoEntrenamiento == "Carrera de velocidad") {
        velocidad += incremento;
        cout << Nombre << " ha mejorado su velocidad en: " << incremento << ". Su velocidad ahora es de:" << velocidad << endl;
    }
    else if (tipoEntrenamiento == "Obstaculos") {
        agilidad += incremento;
        cout << Nombre << " ha mejorado su agilidad en:" << incremento << ". Su agilidad ahora es de:" << agilidad << endl;
    }
    else if (tipoEntrenamiento == "Fuerza de impacto") {
        fuerzaImpacto += incremento;
        cout << Nombre << " ha mejorado su resistencia en:" << incremento << ". Su resistencia ahora es de:" << fuerzaImpacto << endl;
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
    catch (const invalid_argument&e) {
        cout << "Error:" << e.what() << endl;
    }
}

cEmbestida::~cEmbestida()
{
}
