// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "cJinete.h"
#include "cVikingo.h"
#include "CarreradeDragones.h"
#include "BatalladeDragones.h"
#include "EscueladeDragones.h"

int main()
{
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
    //menu
    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Carrera de dragones" << endl;
        cout << "2) Batalla de dragones" << endl;
        cout << "3) Escuela de dragones" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CarreradeDragones();
            break;
        case 2:
            BatalladeDragones();
            break;
        case 3:
            EscueladeDragones();
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

   return 0;
}
