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
#include "cMarejada.h"
#include "cIslaBerk.h"
#include "cEscueladeDragones.h" 

using namespace std;

void AsignarDragonesJinetes(vector<cJinete*>&Jinetes_isla, vector<cDragon*>&Dragones_isla);

int main()
{
    //menu
   
    cAtaque* Ataque1 = new cAtaque("Fuego", "15", "14");
    cAtaque* Ataque2 = new cAtaque("Veneno", "14", "10");
    cAtaque* Ataque3 = new cAtaque("Electricidad", "14", "12");
    cAtaque* Ataque4 = new cAtaque("Fuego", "17", "20");
    cAtaque* Ataque5 = new cAtaque("Fuerza", "15", "14");
    cAtaque* Ataque6 = new cAtaque("Lava", "8", "14");
    cAtaque* Ataque7 = new cAtaque("Hielo", "50", "45");

    vector<cDragon*> Dragones_isla;
    vector<string> Habilidades1 = { "Lanzar fuego", "Piel resistente a la lava" };
    vector<string> Habilidades2 = { "Absorber electricidad", "Camuflaje en tormentas", "Usar rayos para impulsarse al volar" };
    vector<string> Habilidades3 = { "Nadador veloz y sigiloso", "Posee veneno"};
    vector<string> Habilidades4 = { "Lanzar fuego" };
    vector<string> Habilidades5 = { "Dientes retractiles", "Camuflaje de noche", "Velocidad supersonica", "Gran audicion" };
    vector<string> Habilidades6 = { "Piel resistente", "Mandibula fuerte", "Fuego de rocas de su estomago" };
    vector<string> Habilidades7 = { "Aliento de hielo", "Control sobre otros dragones" };

    Dragones_isla.push_back(new cFogonera("Cola Quemante", "Poca paciencia", "Grande", "Naranja", false, 10, 21, 30,  Habilidades4, Ataque4));
    Dragones_isla.push_back(new cFogonera("Muerte Roja", "Poca Paciencia", "Mediano", "Azul", true, 20, 25, 20, Habilidades1, Ataque1));
    Dragones_isla.push_back(new cEmbestida("Chimuelo", "Inteligente", "Mediano", "Negro", true, 20, 18, 30, 12, Habilidades5, Ataque5));
    Dragones_isla.push_back(new cEmbestida("Skrill", "Agresivo", "Grande", "Violeta", false, 19, 10,20, 20, Habilidades2, Ataque3));
    Dragones_isla.push_back(new cMarejada("Salvajibestia", "Robusto", "Gigante", "Blanco", true, 20, 10, Habilidades7, Ataque7));
    Dragones_isla.push_back(new cMarejada("Scaldaron", "Redondo", "Grande", "Verde", true, 20, 15, Habilidades3, Ataque2));

    vector<cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar Iuzchuk", "Juju", "31-03-2004", "Guerrera", Dragones_isla[0], 32));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Robusto", 1.5, 20));
    Personas_isla.push_back(new cVikingo("Nahuel", "Chiariza", "Nahu", "11-12-2003", "Guerrero", Dragones_isla[4], 25));
    Personas_isla.push_back(new cVikingo("Milagros", "Menendez Tuja", "Mili", "26-03-2002", "Artesana", Dragones_isla[5], 41));
    Personas_isla.push_back(new cJinete("Santiago", "Menendez Tuja", "Santi", "28-11-1998", "Fuerte", 3, 45));
    Personas_isla.push_back(new cJinete("Sol", "Segura", "Solci", "01-02-1234", "Alta", 4, 29));

    // me creo un vector de jinetes para utilizarlos en escuela de dragones
    vector<cJinete*> Jinetes_isla;
    for (cPersona* persona : Personas_isla) {
        cJinete* jinete = dynamic_cast<cJinete*>(persona);
        if (jinete != nullptr) {
            Jinetes_isla.push_back(jinete);
        }
    }

    //me copio los dragones en otro vector para la asignación de dragones
    vector<cDragon*> vectorDragones(Dragones_isla);
    for (const auto& dragon : vectorDragones) {
        cout << *dragon << endl;
    }

    // asigno a cada jinete los dragones
    AsignarDragonesJinetes(Jinetes_isla, vectorDragones);

    /*
    // Mostrar información de jinetes
    for (const auto& jinete : Jinetes_isla) {
        cout << *jinete << endl;
    }
    */

    // me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }

    /*
    // Mostrar información de vikingos
    for (const auto& vikingo : Vikingos_isla) {
        cout << *vikingo << endl;
    }
    */


    //PRUEBOOOOO
    cIslaBerk ISLA(Jinetes_isla, Dragones_isla, Vikingos_isla);
    ISLA.mainBerk();
 
    vectorDragones.clear();

    // Eliminar dragones de Dragones_isla solo si no se han movido a otra parte
    for (cDragon* dragon : Dragones_isla) {
        if (dragon != nullptr) {
            delete dragon;
        }
    }
    Dragones_isla.clear();

    // Eliminar jinetes de Jinetes_isla
    for (cJinete* jinete : Jinetes_isla) {
        if (jinete != nullptr) {
            delete jinete;
        }
    }
    Jinetes_isla.clear();

    // Eliminar vikingos de Vikingos_isla
    for (cVikingo* vikingo : Vikingos_isla) {
        if (vikingo != nullptr) {
            delete vikingo;
        }
    }
    Vikingos_isla.clear();

    // Eliminar personas de Personas_isla
    for (cPersona* persona : Personas_isla) {
        if (persona != nullptr) {
            delete persona;
        }
    }
    Personas_isla.clear();

    // Eliminar ataques
    delete Ataque1;
    delete Ataque2;
    delete Ataque3;
    delete Ataque4;
    delete Ataque5;
    delete Ataque6;
    delete Ataque7;
   /*
    for (int i = 0; i < vectorDragones.size(); i++) {
        delete vectorDragones[i];
    }

   for (int i = 0; i < Dragones_isla.size(); i++) {
        delete Dragones_isla[i];
    }

    for (int i = 0; i < Jinetes_isla.size(); i++) {
        delete Jinetes_isla[i];
    }

    for (int i = 0; i < Vikingos_isla.size(); i++) {
        delete Vikingos_isla[i];
    }
    
    delete Ataque1, Ataque2, Ataque3, Ataque4, Ataque5, Ataque6, Ataque7;
    */

   return 0;
}
//fin del main

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



/*
// funcion imprimir personas 
void ListaDePersonas(vector<cPersona*>& Personas_isla) {

    //imprimo todas las personas de la isla
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    }

}
    // Implementación de la función MostrarDragonesMatados
    void MostrarDragonesMatados(const vector<cVikingo*>& Vikingos_isla) {

        cout << "Lista de dragones matados por vikingos:" << endl;
        for (auto vikingo : Vikingos_isla) {
            cout << "Vikingo " << vikingo->getNombre() << ":" << endl;
            vikingo->mostrarDragonesMatados();
        }
    }
*/