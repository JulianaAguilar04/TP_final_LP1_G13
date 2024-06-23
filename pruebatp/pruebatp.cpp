// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include "cJinete.h"
#include "cVikingo.h"

using namespace std;

void EscueladeDragones(vector<cJinete*> &Jinetes_isla, vector<cDragon*>&Dragones_isla);
void EstudioDeDragones(vector<cDragon*>& Dragones_isla);
void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
void EntrenarDragones(vector<cJinete*>& Jinetes_isla,vector<cDragon*>& Dragones_isla);
void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>&Dragones_isla);


int main()
{
    //menu
    cAtaque Ataque1("Fuego", "15", "14");
    cAtaque Ataque2("Veneno", "20", "11");
    cAtaque Ataque3("Electricidad", "14", "12");

    vector<cDragon*> Dragones_isla;
    vector<string>Habilidades1 = { "Volar rapido", "Llamarada"};
    vector<string>Habilidades2 = { "Camuflaje", "Disparar rafagas"};
    vector<string>Habilidades3 = { "Aliento de hielo", "Control sobre dragones" };
    
    Dragones_isla.push_back(new cDragon("Chimuelo", "Inteligente", "Mediano", "Negro", false, 30, 50, Habilidades1, &Ataque1));
    Dragones_isla.push_back(new cDragon("Exterminador", "Rapido", "Mediano", "Transparente", true, 30, 50, Habilidades1, &Ataque2));
    Dragones_isla.push_back(new cDragon("Skrill", "Agresivo", "Grande", "Violeta", false, 30, 50, Habilidades1, &Ataque3));
    Dragones_isla.push_back(new cDragon("Furia luminosa", "Salvaje", "Chico", "Blanco", true, 20, 18, Habilidades2, &Ataque1));
    Dragones_isla.push_back(new cDragon("Salvajibestia", "Robusto", "Gigante", "Gris", true, 6, 40, Habilidades3,&Ataque1));


    vector <cDragon*> ::iterator it_d = Dragones_isla.begin();

    while (it_d != Dragones_isla.end()) {
        cout << *(*it_d) << endl;
        it_d++;
    }

    cDragon Dragon4("Skrill", "Agresivo", "Grande", "Violeta", false, 50, 30, Habilidades1, &Ataque3);
    cDragon Dragon5("Furia luminosa", "Salvaje", "Chico", "Blanco", true, 20, 18, Habilidades2, &Ataque1);
    cDragon Dragon6("Salvajibestia", "Robusto", "Gigante", "Gris", true, 6, 40, Habilidades3, &Ataque1);

    vector <cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar", "Juju", "31-03-2004", "Guerrera", Dragon4, 32));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Lloron", 1.5, 20));
    Personas_isla.push_back(new cVikingo("Elias", "Garcia", "Elu", "19-06-2002", "Guerrero", Dragon4, 20));
    Personas_isla.push_back(new cVikingo("Milagros", "Menendez Tuja", "Mili", "26-03-2002","Artesana", Dragon5, 41));
    Personas_isla.push_back(new cJinete("Santiago", "Menendez Tuja", "Santi", "28-11-1998", "Estratega", 20 , 45));
    
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    } 

    //me creo un vetor de jinetes para utilizarlos en escuela de dragones
    vector<cJinete*> Jinetes_isla;
    for (cPersona* persona : Jinetes_isla) {
        cJinete* jinete = dynamic_cast<cJinete*>(persona);
        if (jinete != nullptr) {
            Jinetes_isla.push_back(jinete);
        }
    }

    //me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }

    vector<std::string> habilidadesIniciales = { "volar rápido", "llamarada" };
    cDragon dragon1("Furia", "Inteligente","Chico", "Negro", true,  300, 500, habilidadesIniciales, &Ataque1);
    cJinete entrenador1("Hipo", "Iuzchuk", "Ache", "23-11-2001", "Herrero", 1.5, 30); //nivel de fuerza?

    dragon1.mostrarHabilidades();

    dragon1.Entrenar("velocidad", entrenador1);
    dragon1.Entrenar("resistencia", entrenador1);
    dragon1.Entrenar("habilidades", entrenador1);

    dragon1.mostrarHabilidades();


    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Escuela de dragones" << endl;
        cout << "2) Carrera de dragones" << endl;
        cout << "3) Batalla de dragones" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            EscueladeDragones(Jinetes_isla, Dragones_isla);
            break;
        case 2:
            cout << "Aqui va la opcion de carrera de dragones" << endl;
            break;
        case 3:
            BatalladeDragones(Vikingos_isla, Dragones_isla);
            break;
        case 4:
            cout << "Muchas gracias por visitar la Isla de Berk" << endl;
            break;

        default:
            cout << "Opcion invalida: Intentelo de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (opcion != 4);


    
    for (int i = 0; i < Dragones_isla.size(); i++) {
        delete Dragones_isla[i];
    }

    for (int i = 0; i < Personas_isla.size(); i++) {
        delete Personas_isla[i];
    }

   return 0;
}
//fin del main


//--------------------------------------------------------------------------------ESCUELA DE DRAGONES
void EscueladeDragones(vector<cJinete*>& Jinetes_isla, vector<cDragon*>& Dragones_isla) {
    int opcion;
    do {
        cout << "\nUSTED ESTA EN LA ESCUELA DE LA ISLA" << endl;
        cout << "1) Estudio de dragones" << endl;
        cout << "2) Lista de dragones conocidos " << endl;
        cout << "3) Entrenar " << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            EstudioDeDragones(Dragones_isla);
            break;
        case 2:
            ListaDeDragones(Dragones_isla);
            break;
        case 3:
            EntrenarDragones(Jinetes_isla,Dragones_isla);
            break;

        case 4:
            cout << "Saliendo de la Escuela de Dragones..." << endl;
            break;

        default:
            cout << "Opcion invalida: Vuelva a intentarlo" << endl;
            break;
        }

    } while (opcion != 4);
}


void EstudioDeDragones(vector<cDragon*>& Dragones_isla) {
    string nombre, caracteristica, tamano, color;
    int velocidad=0, resistencia=0, hab=0;
    bool estado;
    char domado;
    vector<string> v_habilidades;

    cout << "Ustdes ha encontrado un nuevo dragon!" << endl;
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
    cout << "Ingrese la velocidad del dragon:" << endl;
    cin >> velocidad;
    cout << "Ingrese la resistencia del dragon:" << endl;
    cin >> resistencia;
    cout << "Ingrese las habilidades del dragon:" << endl;
    cout << "Cantidad:" << endl;
    cin >> hab;

    v_habilidades.reserve(hab); //reservo espacio para la cantidades de habilidades
    for (int i = 0; i < hab; i++)
    {
        string habilidad;
        cout << "Ingrese habilidad:" << (i+1) <<":" << endl;
        cin >> habilidad;
        v_habilidades.push_back(habilidad);
    }

    string tipoAtaque, danioAtaque, alcanceAtaque;
    cout << "Ingrese el tipo de ataque del dragón: ";
    cin >> tipoAtaque;
    cout << "Ingrese el daño del ataque del dragón: ";
    cin >> danioAtaque;
    cout << "Ingrese el alcance del ataque del dragón: ";
    cin >> alcanceAtaque;
    cAtaque* ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);

    // Crear el nuevo objeto cDragon y agregarlo al vector
    Dragones_isla.push_back(new cDragon(nombre, caracteristica, tamano, color, estado, velocidad, resistencia, v_habilidades, ataque));
    cout << "Dragon agregado exitosamente!" << endl;
}

void ListaDeDragones(const vector<cDragon*>& Dragones_isla) {
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (const auto& dragon : Dragones_isla) {
        cout << dragon->to_string();
    }
}

void EntrenarDragones(vector<cJinete*>& Jinetes_isla, vector<cDragon*>& Dragones_isla) {

    vector<cJinete*>::iterator it_j = Jinetes_isla.begin();
    vector<cDragon*>::iterator it_d = Dragones_isla.begin();

    while (it_j != Jinetes_isla.end()) {
        cJinete& JineteActual = **it_j;
        while (it_d != Dragones_isla.end()) {
            (*it_d)->Entrenar("Velocidad", JineteActual);
            ++it_d;
        }
        ++it_j;
        it_d = Dragones_isla.begin();
    }

    /*for (auto& dragon : Dragones_isla) {
        if (dragon->getEstado()) {
            dragon->Entrenar();
            cout << "El dragon " << dragon->getNombre() << " ha sido entrenado." << endl;
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " no esta domado y no puede ser entrenado." << endl;
        }
    }
    */
}

    // BATALLA DE DRAGONES ------------------------------------------------------------------
    // Implementación de la función BatalladeDragones
    void BatalladeDragones(vector<cVikingo*>&Vikingos_isla, vector<cDragon*>&Dragones_isla) {
        cout << "¡La aldea está en peligro! ¡Prepárense para la batalla contra los dragones malos!" << endl;

        // Filtrar dragones malos (no domados)
        vector<cDragon*> dragonesMalos;
        for (auto dragon : Dragones_isla) {
            if (!dragon->getEstado()) {
                dragonesMalos.push_back(dragon);
            }
        }

        // Verificar si hay dragones malos para combatir
        if (dragonesMalos.empty()) {
            cout << "No hay dragones malos para combatir." << endl;
            return;
        }

        // Seleccionar aleatoriamente un vikingo y un dragón malo
        cVikingo* vikingo = Vikingos_isla[rand() % Vikingos_isla.size()];
        cDragon* dragonMalo = dragonesMalos[rand() % dragonesMalos.size()];

        cout << "El vikingo " << vikingo->getNombre() << " se enfrenta al dragón " << dragonMalo->getNombre() << "." << endl;

        // Comparar fuerza del vikingo con resistencia del dragón
        if (vikingo->getFuerza() >= dragonMalo->getResistencia()) {
            cout << "¡El vikingo " << vikingo->getNombre() << " ha derrotado al dragón " << dragonMalo->getNombre() << "!" << endl;
            vikingo->registrarDragonMatado(dragonMalo->getNombre());

            // Eliminar el dragón de la lista de dragones
            auto it = find(Dragones_isla.begin(), Dragones_isla.end(), dragonMalo);
            if (it != Dragones_isla.end()) {
                delete* it;
                Dragones_isla.erase(it);
            }
        }
        else {
            cout << "El dragón " << dragonMalo->getNombre() << " ha vencido al vikingo " << vikingo->getNombre() << "." << endl;
        }
    }

