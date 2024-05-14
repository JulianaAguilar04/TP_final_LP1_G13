#pragma once
#include <iostream>
#include <string>
using namespace std;


class cDragon
{
private:
	string Nombre;
	string Caracteristica;
	string Tamano;
	string Color;
	bool Estado;
	//cAtaque* FormadeAtaque;

public:
	cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado);
	//constructor por copia
	cDragon(const cDragon& Dragoncito) : Nombre(Dragoncito.Nombre), Caracteristica(Dragoncito.Caracteristica), Tamano(Dragoncito.Tamano), Color(Dragoncito.Color), Estado(Dragoncito.Estado) {};
	string getNombre();
	string getCaracteristica();
	string getTamano();
	string getColor();
	bool getEstado();
	void setNombre(string nuevoNombre);
	void setCaracteristica(string nuevaCaracteristica);
	void setTamano(string nuevoTamano);
	void setColor(string nuevoColor);
	void setEstado(bool nuevoEstado);
	string AltaNombre(string Nombre);
	bool Domado();
	//Entrenar();
	//Baja();
};



