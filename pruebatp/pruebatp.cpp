// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include "cJinete.h"
#include "cVikingo.h"
#include "cEmbestida.h"
#include "cFogonera.h"
#include "cPiedra.h"
#include "cMarejada.h"
#include "cRastreadora.h"

using namespace std;

void AsignarDragonesJinetes(vector<cJinete*>&Jinetes_isla, vector<cDragon*>&Dragones_isla);

void EscueladeDragones(vector<cJinete*> &Jinetes_isla, vector<cDragon*>&Dragones_isla);
void EstudioDeDragones(vector<cDragon*>& Dragones_isla);
void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
void EntrenarDragones(vector<cJinete*>& Jinetes_isla);
void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>&Dragones_isla);
void ListaDePersonas(vector<cPersona*>& Personas_isla);

int main()
{
    //menu
   
    cAtaque* Ataque1 = new cAtaque("Fuego", "15", "14");
    cAtaque* Ataque2 = new cAtaque("Fuerza", "9", "13");
    cAtaque* Ataque3 = new cAtaque("Electricidad", "14", "12");
    cAtaque* Ataque4 = new cAtaque("Fuego", "17", "20");
    cAtaque* Ataque5 = new cAtaque("Fuerza", "15", "14");
    cAtaque* Ataque6 = new cAtaque("Lava", "8", "14");
    cAtaque* Ataque7 = new cAtaque("Hielo", "50", "45");

    vector<cDragon*> Dragones_isla;
    vector<string> Habilidades1 = { "Lanzar fuego", "Piel resistente a la lava" };
    vector<string> Habilidades2 = { "Absorber electricidad", "Camuflaje en tormentas", "Usar rayos para impulsarse al volar" };
    vector<string> Habilidades3 = { "Dientes afilados", "Resistencia fisica", "Dispara llamaradas de napalm" };
    vector<string> Habilidades4 = { "Lanzar fuego" };
    vector<string> Habilidades5 = { "Dientes retractiles", "Camuflaje de noche", "Velocidad supersonica", "Gran audicion" };
    vector<string> Habilidades6 = { "Piel resistente", "Mandibula fuerte", "Fuego de rocas de su estomago" };
    vector<string> Habilidades7 = { "Aliento de hielo", "Control sobre otros dragones" };

    Dragones_isla.push_back(new cFogonera("Cola Quemante", "Poca paciencia", "Grande", "Naranja", false, 15, 15, Habilidades4, Ataque4));
    Dragones_isla.push_back(new cFogonera("Muerte Roja", "Poca Paciencia", "Mediano", "Azul", true, 6, 30, Habilidades1, Ataque1));
    Dragones_isla.push_back(new cEmbestida("Chimuelo", "Inteligente", "Mediano", "Negro", true, 20, 18, Habilidades5, Ataque5));
    Dragones_isla.push_back(new cEmbestida("Skrill", "Agresivo", "Grande", "Violeta", false, 19, 10, Habilidades2, Ataque3));
    Dragones_isla.push_back(new cPiedra("Colmillo Afilado", "Juegueton", "Chico", "Celeste", true, 5, 17, Habilidades3, Ataque1));
    Dragones_isla.push_back(new cPiedra("Gronckle", "Robusto", "Mediano", "Marron", true, 4, 20, Habilidades6, Ataque6));
    Dragones_isla.push_back(new cMarejada("Salvajibestia", "Robusto", "Gigante", "Blanco", true, 6, 40, Habilidades7, Ataque7));

    vector<cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar", "Juju", "31-03-2004", "Guerrera", Dragones_isla[0], 32));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Lloron", 1.5, 20));
    Personas_isla.push_back(new cVikingo("Elias", "Garcia", "Elu", "19-06-2002", "Guerrero", Dragones_isla[4], 20));
    Personas_isla.push_back(new cVikingo("Milagros", "Menendez Tuja", "Mili", "26-03-2002", "Artesana", Dragones_isla[5], 41));
    Personas_isla.push_back(new cJinete("Santiago", "Menendez Tuja", "Santi", "28-11-1998", "Estratega", 3, 45));

    // me creo un vector de jinetes para utilizarlos en escuela de dragones
    vector<cJinete*> Jinetes_isla;
    for (cPersona* persona : Personas_isla) {
        cJinete* jinete = dynamic_cast<cJinete*>(persona);
        if (jinete != nullptr) {
            Jinetes_isla.push_back(jinete);
        }
    }

    // asigno a cada jinete los dragones
    AsignarDragonesJinetes(Jinetes_isla, Dragones_isla);

    // Mostrar información de jinetes
    for (const auto& jinete : Jinetes_isla) {
        cout << *jinete << endl;
    }

    // me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }

    // Mostrar información de vikingos
    for (const auto& vikingo : Vikingos_isla) {
        cout << *vikingo << endl;
    }

    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Escuela de dragones" << endl;
        cout << "2) Batalla de dragones" << endl;
        cout << "3) Lista de habitantes de la isla" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            EscueladeDragones(Jinetes_isla, Dragones_isla);
            break;
        case 2:
            BatalladeDragones(Vikingos_isla, Dragones_isla);
            break;
        case 3:
            ListaDePersonas(Personas_isla);
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

    for (int i = 0; i < Jinetes_isla.size(); i++) {
        delete Jinetes_isla[i];
    }

    for (int i = 0; i < Vikingos_isla.size(); i++) {
        delete Vikingos_isla[i];
    }


   return 0;
}
//fin del main

// funcion imprimir personas 
void ListaDePersonas(vector<cPersona*>& Personas_isla) {

    //imprimo todas las personas de la isla
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    }

}

//funcion asignar dragones
void AsignarDragonesJinetes(vector<cJinete*>& Jinetes_isla, vector<cDragon*>& Dragones_isla) {

    for (auto& jinete : Jinetes_isla) {

        vector<cDragon*>::iterator it_d = Dragones_isla.begin();

        while (it_d != Dragones_isla.end()) {

            if ((*it_d)->getEstado() == true && jinete->getEfectividad() > 1.0) {
                bool yaTieneJinete = false;
                for (cJinete* otroJinete : Jinetes_isla) {
                    if (otroJinete != jinete && otroJinete->tieneDragon(*it_d)) {
                        yaTieneJinete = true;
                        break;
                    }
                }
                if (!yaTieneJinete) {
                    jinete->IncorporarDragon(*it_d);
                    it_d = Dragones_isla.erase(it_d);
                }
                else {
                    ++it_d;
                }
            }
            else {
                ++it_d;
            }
        }
    }

}

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
            EntrenarDragones(Jinetes_isla);
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

    cout << "Usted ha encontrado un nuevo dragon!" << endl;
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
    cout << "HABILIDADES" << endl;
    cout << "Cantidad de habilidades:" << endl;
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

void EntrenarDragones(vector<cJinete*>& Jinetes_isla) {

    for (cJinete* jinete : Jinetes_isla) {
        //obtengo la lista de dragones del jinete
        vector<cDragon*> dragones = jinete->getMisDragones();
        for (cDragon* dragon : dragones) {
            //entreno cada dragon de la lista del jinete
            dragon->Entrenar("Velocidad", (*jinete));
            dragon->Entrenar("Resistencia", (*jinete));
            dragon->Entrenar("Habilidades", (*jinete));
        }
    }
}


    // BATALLA DE DRAGONES ------------------------------------------------------------------
    // Implementación de la función BatalladeDragones
    void BatalladeDragones(vector<cVikingo*>&Vikingos_isla, vector<cDragon*>&Dragones_isla) {
        cout << "La aldea esta en peligro! Preparense para la batalla contra los dragones malos!" << endl;

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

        cout << "El vikingo " << vikingo->getNombre() << " se enfrenta al dragon " << dragonMalo->getNombre() << "." << endl;

        // Comparar fuerza del vikingo con resistencia del dragón
        if (vikingo->getFuerza() >= dragonMalo->getResistencia()) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragonMalo->getNombre() << "!" << endl;
            vikingo->registrarDragonMatado(dragonMalo->getNombre());

            // Eliminar el dragón de la lista de dragones
            auto it = find(Dragones_isla.begin(), Dragones_isla.end(), dragonMalo);
            if (it != Dragones_isla.end()) {
                delete* it;
                Dragones_isla.erase(it);
            }
        }
        else {
            cout << "El dragon " << dragonMalo->getNombre() << " ha vencido al vikingo " << vikingo->getNombre() << "." << endl;
        }
    }

