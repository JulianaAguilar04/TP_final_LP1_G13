#pragma once
#include <iostream>
#include <string>
using namespace std;

void EscueladeDragones()
{
	int opcion;

	do {
		cout << "1) Estudio de dragones " << endl;
		cout << "2) Lista de dragones conocidos " << endl;
		cout << "3) Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			break;

		case 2:
			break;

		default:
			cout << "Error" << endl;
			break;

		}

	} while (opcion != 3);
}

