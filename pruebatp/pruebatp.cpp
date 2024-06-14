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
#include "cJinete.h"
#include "cVikingo.h"
#include "CarreradeDragones.h"
#include "BatalladeDragones.h"
#include "EscueladeDragones.h"
using namespace std;


int main()
{
    //menu
    cAtaque Ataque1("Fuego", "15", "14");
    cAtaque Ataque2("Veneno", "20", "11");
    cAtaque Ataque3("Electricidad", "14", "12");

    vector <cDragon*> Dragones_isla;
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
            EscueladeDragones();
            break;
        case 2:
            CarreradeDragones();
            break;
        case 3:
            BatalladeDragones();
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
