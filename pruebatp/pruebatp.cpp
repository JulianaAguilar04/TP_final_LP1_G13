// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include <stdexcept>
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
   //Ataques
    cAtaque* Ataque1 = new cAtaque("Fuego", "15", "14");
    cAtaque* Ataque2 = new cAtaque("Veneno", "14", "10");
    cAtaque* Ataque3 = new cAtaque("Electricidad", "14", "12");
    cAtaque* Ataque4 = new cAtaque("Fuego", "17", "20");
    cAtaque* Ataque5 = new cAtaque("Fuerza", "15", "14");
    cAtaque* Ataque6 = new cAtaque("Lava", "8", "14");
    cAtaque* Ataque7 = new cAtaque("Hielo", "50", "45");
    cAtaque* Ataque8 = new cAtaque("Gel de fuego", "15", "15");
    cAtaque* Ataque9 = new cAtaque("Plasma explosiva", "15", "14");
    cAtaque* Ataque10 = new cAtaque("Onda sonica", "16", "12");

    //Habilidades
    vector<string> Habilidades1 = { "Lanzar fuego", "Piel resistente a la lava" };
    vector<string> Habilidades2 = { "Absorber electricidad", "Camuflaje en tormentas", "Usar rayos para impulsarse al volar" };
    vector<string> Habilidades3 = { "Nadador veloz y sigiloso", "Posee veneno"};
    vector<string> Habilidades4 = { "Lanzar fuego" };
    vector<string> Habilidades5 = { "Dientes retractiles", "Camuflaje de noche", "Velocidad supersonica", "Gran audicion" };
    vector<string> Habilidades6 = { "Piel resistente", "Mandibula fuerte", "Fuego de rocas de su estomago" };
    vector<string> Habilidades7 = { "Aliento de hielo", "Control sobre otros dragones" };
    vector<string> Habilidades8 = { "Prende fuego su cuerpo", "Crea rafagas de viento" };
    vector<string> Habilidades9 = { "Camuflaje entre las nubes", "Velocidad supersonica", "Sigilosa" };
    vector<string> Habilidades10 = { "Extingue llamas", "Deja sordos a sus oponentes" };

    //Dragones de la isla
    vector<cDragon*> Dragones_isla;
    Dragones_isla.push_back(new cFogonera("Cola Quemante", "Poca paciencia", "Grande", "Naranja", true, 10, 21, 30,  Habilidades4, Ataque4));
    Dragones_isla.push_back(new cFogonera("Muerte Roja", "Poca Paciencia", "Mediano", "Azul", false, 20, 25, 20, Habilidades1, Ataque1));
    Dragones_isla.push_back(new cEmbestida("Chimuelo", "Inteligente", "Mediano", "Negro", true, 20, 18, 30, 12, Habilidades5, Ataque5));
    Dragones_isla.push_back(new cEmbestida("Skrill", "Agresivo", "Grande", "Violeta", false, 19, 10,20, 20, Habilidades2, Ataque3));
    Dragones_isla.push_back(new cMarejada("Salvajibestia", "Robusto", "Gigante", "Blanco", true, 20, 10, Habilidades7, Ataque7));
    Dragones_isla.push_back(new cMarejada("Scaldaron", "Redondo", "Grande", "Verde", true, 20, 15, Habilidades3, Ataque2));
    Dragones_isla.push_back(new cFogonera("Pesadilla Monstruosa", "Irritable", "Mediano", "Purpura", false, 15, 20, 17, Habilidades8, Ataque8));
    Dragones_isla.push_back(new cEmbestida("Furia Luminosa", "Salvaje", "Mediano", "Blanco", true, 18, 20, 28, 14, Habilidades9, Ataque9));
    Dragones_isla.push_back(new cMarejada("Trueno Tambor", "Solitario", "Pequenio", "Azul", false, 10, 7, Habilidades10, Ataque10));


    //Personas de la isla
    vector<cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar Iuzchuk", "Juju", "31-03-2004", "Constructora", 32));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Robusto", ResulEntrenamiento::Aprobado, 20));
    Personas_isla.push_back(new cVikingo("Nahuel", "Chiariza", "Nahu", "11-12-2003", "Herrero", 25));
    Personas_isla.push_back(new cVikingo("Milagros", "Menendez Tuja", "Mili", "26-03-2002", "Agricultora", 41));
    Personas_isla.push_back(new cJinete("Santiago", "Menendez Tuja", "Santi", "28-11-1998", "Fuerte", ResulEntrenamiento::Primero, 45));
    Personas_isla.push_back(new cJinete("Sol", "Segura", "Solci", "01-02-1234", "Alta", ResulEntrenamiento:: Ultimo, 29));
    Personas_isla.push_back(new cJinete ("Maribel","Papa", "Maru", "28-11-2003", "Inteligente", ResulEntrenamiento::Desaprobado, 20));
    Personas_isla.push_back(new cJinete("Maria Sol", "Maidana Cendra", "Solchu","01-08-2003", "Peleadora", ResulEntrenamiento::Aprobado, 25));
    Personas_isla.push_back(new cVikingo("Federico", "Grano", "Fede", "30-11-2003", "Pescador", 30));



    // me creo un vector de jinetes para utilizarlos en escuela de dragones
    vector<cJinete*> Jinetes_isla;
    for (cPersona* persona : Personas_isla) {
        cJinete* jinete = dynamic_cast<cJinete*>(persona);
        if (jinete != nullptr) {
            Jinetes_isla.push_back(jinete);
        }
    }

    // me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }

    //me copio los dragones en otro vector para la asignacion de dragones
    vector<cDragon*> vectorDragones(Dragones_isla);

    AsignarDragonesJinetes(Jinetes_isla, vectorDragones);
 

    cIslaBerk ISLA(Jinetes_isla, Dragones_isla, Vikingos_isla);
    ISLA.mainBerk();
    
    vectorDragones.clear();

    // Eliminar dragones de Dragones_isla 
    for (cDragon* dragon : Dragones_isla) {
        if (dragon != nullptr) {
            delete dragon;
        }
    }
    Dragones_isla.clear();

    //Eliminar personas de Personas_isla
    for (int i = 0; i < Personas_isla.size(); i++) {
        delete Personas_isla[i];
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
    delete Ataque8;
    delete Ataque9;
    delete Ataque10;

    return 0;
}


//funcion asignar dragones
void AsignarDragonesJinetes(vector<cJinete*>& Jinetes_isla, vector<cDragon*>& Dragones_isla) {
    
    int indexDragon = 0;

    for (cJinete* jinete : Jinetes_isla) {
        // Reinicio el indice si alcanza el final del vector
        if (indexDragon >= Dragones_isla.size()) {
            break;
        }

        // Compruebo si el jinete puede tener un dragón (debe tener una calificacion de bocon)
        if (jinete->getResultado() > 0) {
            bool asignado = false;

            // Busco un dragón disponible para el jinete actual
            while (indexDragon < Dragones_isla.size() && !asignado) {
                cDragon* dragon = Dragones_isla[indexDragon];

                // Verifio que el dragón este disponible
                if (dragon->getEstado() == true) {
                    bool yaTieneJinete = false;

                    // Verifico que el dragón no este ya asignado a otro jinete
                    for (cJinete* otroJinete : Jinetes_isla) {
                        if (otroJinete->tieneDragon(dragon)) {
                            yaTieneJinete = true;
                            break;
                        }
                    }

                    // Asigno el dragón al jinete si no tiene jinete
                    if (!yaTieneJinete) {
                        jinete->IncorporarDragon(dragon);
                        asignado = true;
                    }
                }
                indexDragon++;
            }
        }
    }

}
