// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
    //instancia de ataque utilizando constructor de parámetros
cAtaque Ataque1("Fuego", "15", "14");
cout << Ataque1.to_string() << endl;

//instancia de dragón utilizando el constructor por parámetros 
cDragon Dragon1("Chimuelo", "Inteligente", "Mediano", "Negro", false, &Ataque1); //false: no esta domado
cout << Dragon1.to_string() << endl;

//instancia de dragón utilizando el constructor por copia-parámetro
cDragon Dragon2(Dragon1);
cout << Dragon2.to_string() << endl;

//
cAtaque Ataque2("Veneno", "20", "11");
cout << Ataque2.to_string() << endl;
cout << "\n" << endl;

cDragon Dragon3("Exterminador", "Rapido", "Mediano", "Transparente", true, &Ataque2);
cout << Dragon3.to_string() << endl;

//instancia de jinete utilizando constructor por parámetros
cJinete Jinete1("Astrid", "Hofferson", "Astru", "05-09-2010", "Lider", &Dragon3);
cout << Jinete1.to_string() << endl;

//
cout << "PRUEBA VIKINGO" << endl;
cAtaque Ataque3("Electricidad", "14", "12");
cDragon Dragon4("Skrill", "Agresivo", "Grande", "Violeta", false, &Ataque3);

//instancia de vikingo utilizando constructor por defecto
cVikingo Vikingo1("Daniela", "Iuzchuk", "Polaca", "04-01-1976", "Cazadora", Dragon4);
cout << "Informacion de Daniela:\n" << Vikingo1.to_string() << endl;

cVikingo Vikingo2("Maribel", "Papa", "Maru", "28-11-2003", "Tecnica", Dragon3);
cout << "Informacion de Maribel: \n" << Vikingo2.to_string() << endl;
*/

#include <iostream>
#include <vector>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include "cJinete.h"
#include "cVikingo.h"
#include "CarreradeDragones.h"
#include "BatalladeDragones.h"
#include "EscueladeDragones.h"
using namespace std;

void EscueladeDragones(vector<cDragon*>&Dragones_isla);
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones);
// void Entrenar();
static void Entrenar(cPersona* Persona);


int main()
{
    //menu
    cAtaque Ataque1("Fuego", "15", "14");
    cAtaque Ataque2("Veneno", "20", "11");
    cAtaque Ataque3("Electricidad", "14", "12");

    vector<cDragon*> Dragones_isla;
    Dragones_isla.push_back(new cDragon("Chimuelo", "Inteligente", "Mediano", "Negro", false, &Ataque1));
    Dragones_isla.push_back(new cDragon("Exterminador", "Rapido", "Mediano", "Transparente", true, &Ataque2));
    Dragones_isla.push_back(new cDragon("Skrill", "Agresivo", "Grande", "Violeta", false, &Ataque3));


    vector <cDragon*> ::iterator it_d = Dragones_isla.begin();

    while (it_d != Dragones_isla.end()) {
        cout << *(*it_d) << endl;
        it_d++;
    }

    cDragon Dragon4("Skrill", "Agresivo", "Grande", "Violeta", false, &Ataque3);

    vector <cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar", "Juju", "31-03-2004", "Guerrera", Dragon4));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Lloron"));
    Personas_isla.push_back(new cVikingo("Elias", "Garcia", "Elu", "19-06-2002", "Guerrero", Dragon4));
    
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    } 

    //me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }


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
            EscueladeDragones(Dragones_isla); 
            break;
        case 2:
            CarreradeDragones();
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

void EscueladeDragones(vector<cDragon*>& Dragones_isla) {
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
            EntrenarDragones(Dragones_isla);
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
    bool estado;
    char domado;
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

    cAtaque* ataque = nullptr;  // Inicialmente sin ataque asignado
    Dragones_isla.push_back(new cDragon(nombre, caracteristica, tamano, color, estado, ataque));

    cout << "Dragon agregado exitosamente!" << endl;
}

void ListaDeDragones(const vector<cDragon*>& Dragones_isla) {
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (const auto& dragon : Dragones_isla) {
        cout << dragon->to_string();
    }
}

void EntrenarDragones(vector<cDragon*>& Dragones_isla) {
    for (auto& dragon : Dragones_isla) {
        if (dragon->getEstado()) {
            dragon->Entrenar();
            cout << "El dragon " << dragon->getNombre() << " ha sido entrenado." << endl;
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " no esta domado y no puede ser entrenado." << endl;
        }
    }
}

//batalla dragones cpp
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones) {
    cVikingo::AtacarDragones(); // Enviar mensaje a los vikingos

    cout << "La batalla ha comenzado!" << endl;

    // Simulación simple de la batalla
    srand(time(0));
    for (auto& vikingo : vikingos) {
        if (dragones.empty()) {
            cout << "Todos los dragones han sido derrotados!" << endl;
            return;
        }

        int dragonIndex = rand() % dragones.size();
        cDragon* dragon = dragones[dragonIndex];

        // Ejemplo simple de combate: 50% de probabilidad de que el vikingo gane
        if (rand() % 2 == 0) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragon->getNombre() << endl;
            vikingo->registrarDragonMatado(dragon->getNombre());
            dragones.erase(dragones.begin() + dragonIndex); // Eliminar dragón derrotado
            delete dragon; // Liberar memoria del dragón eliminado
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " ha derrotado al vikingo " << vikingo->getNombre() << endl;
        }
    }

    cout << "La batalla ha terminado!" << endl;
}

/*
void EscueladeDragones(vector<cDragon*>Dragones_isla) {
    int opcion;
    do {
        cout << "\n USTED ESTA EN LA ESCUELA DE LA ISLA" << endl;
        cout << "1) Estudio de dragones" << endl;
        cout << "2) Lista de dragones conocidos " << endl;
        cout << "3) Entrenar " << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
            //Entrenar();
            void Entrenar(cPersona * Persona);
            break;

        default:
            cout << "Opcion invalida: Vuelva a intentarlo" << endl;
            break;

        }

    } while (opcion != 4);

}
*/
/*CORRECCION:
la hice que sea estatica porq sino tiraba error, antes decia lo mismo pero sin static 
y le puse puntero, lo arregle solo para q no me tiraba error pero seguro no esta bien 
antes era: "void Entrenar(cPersona Persona, ) {} "

Tambien la modifique en lo lugares q la llamaba ( prubatp.cpp linea 51/52 , pruebatp.cpp linea 152/153) 
*/
static void Entrenar(cPersona* Persona)
{

}