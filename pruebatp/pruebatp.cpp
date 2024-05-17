// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "cDragon.h"
#include "cJinete.h"
#include "cVikingo.h"
#include "cAtaque.h"


int main()
{
    cAtaque Ataque1("Fuego", "15", "14");

    cDragon Dragon1("Chimuelo", "Inteligente", "Mediano", "Negro", false, &Ataque1 );//false: no esta domado
    cout << Dragon1.to_string() << endl;
    /*
    cout << "Nombre:" << Dragon1.getNombre() << endl;
    cout << "Caracteristica:" << Dragon1.getCaracteristica() << endl;
    cout << "Tamano:" << Dragon1.getTamano() << endl;
    cout << "Color:" << Dragon1.getColor() << endl;
    if (Dragon1.getEstado() == false) {
        cout << "No esta domado" << endl;
    }
    else {
        cout << "Esta domado" << endl;
    }
    */

    //quiero chequear que es este tp

    cDragon Dragon2 = Dragon1;
    cout << "Nombre:" << Dragon2.getNombre() << endl;
    cout << "Caracteristica:" << Dragon2.getCaracteristica() << endl;
    cout << "Tamano:" << Dragon2.getTamano() << endl;
    cout << "Color:" << Dragon2.getColor() << endl;
    if (Dragon2.getEstado() == false) {
        cout << "No esta domado" << endl;
    }
    else {
        cout << "Esta domado" << endl;
    }
    cout << endl;

    cAtaque Ataque2("Veneno", "20", "11");
    cout << Ataque2.to_string() << endl;
    cout << "\n" << endl;

    cDragon Dragon3("Exterminador", "Rapido", "Mediano", "Transparente", true, &Ataque2);
    cout << Dragon3.to_string() << endl;

    cJinete Jinete1("Astrid", "Hofferson", "Astru", "05-09-2010", "Lider", &Dragon3);
    cout << Jinete1.to_string() << endl;

    cVikingo Vikingo1;
    Vikingo1.setNombre("Bocon");
    Vikingo1.setApellido("Rudo");
    Vikingo1.setPosicion("Herrero");
    cout << Vikingo1.to_string() << endl;

   return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
