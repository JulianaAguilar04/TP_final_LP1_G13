// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "cDragon.h"
#include "cJinete.h"
#include "cVikingo.h"


int main()
{
    /*
    cDragon Dragoncito("Chimuelo", "Negrito", "Mediano", "Negro", "Domado");
    cVikingo Vikinguito("Juliana", "Aguilar", "Frente");
    cJinete Jinetito("Tatiana", "Villegas", "Tati", "2004-04-15", "Rapida", &Dragoncito);

    cout << Jinetito.getNombre() << endl;
    cout << Jinetito.getApellido() << endl;
    cout << Jinetito.getApodo() << endl;
    cout << Jinetito.getCaracteristicas() << endl;
    */
    cDragon Dragon("Chimuelo", "Inteligente", "Mediano", "Negro", false);//false: no esta domado
    cout << "Nombre:" << Dragon.getNombre() << endl;
    cout << "Caracteristica:" << Dragon.getCaracteristica() << endl;
    cout << "Tamano:" << Dragon.getTamano() << endl;
    cout << "Color:" << Dragon.getColor() << endl;
    if (Dragon.getEstado() == false) {
        cout << "No esta domado" << endl;
    }
    else {
        cout << "Esta domado" << endl;
    }

    cDragon Dragon2 = Dragon;
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
