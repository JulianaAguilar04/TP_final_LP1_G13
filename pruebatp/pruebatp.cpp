// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "cJinete.h"
#include "cVikingo.h"


int main()
{
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
    /*
    Vikingo1.setNombre("Bocon");
    Vikingo1.setApellido("Rudo");
    Vikingo1.setPosicion("Herrero");
    cout << Vikingo1.mostrar() << endl;
    */
   return 0;
}
