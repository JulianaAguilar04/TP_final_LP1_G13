#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "cAtaque.h"
using namespace std;

class cJinete;

class cDragon
{
private:
	string Nombre;
	string Caracteristica;
	string Tamano;
	string Color;
	bool Estado;
	int Velocidad;
	int Resistencia;
	vector<string> Habilidades; //agregue velocidad, reisstencia, nivel de entrenamiento y habilidades
	int NivelEntrenamiento;
	cAtaque* FormadeAtaque = nullptr;


public:
	//constructor por parametros 
	cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Resistencia,vector <string> Habilidades, cAtaque* miAtaque);
	//constructor por copia
	cDragon(cDragon& Dragoncito);
	string getNombre();
	string getCaracteristica();
	string getTamano();
	string getColor();
	bool getEstado();
	void setCaracteristica(string nuevaCaracteristica);
	void setTamano(string nuevoTamano);
	void setColor(string nuevoColor);
	void setEstado(bool nuevoEstado);	
	void AltaNombre(string Nombre);			//funcion que se pide
	bool Domado();							//funcion que se pide
	string to_string();
	friend ostream& operator<<(ostream& s, cDragon& d);
	// void AltaDragon(cDragon *dragon); ???
	void Entrenar(string tipoEntrenamiento, cJinete &Jinete);							//funcion que se pide 
	void Baja(vector<cDragon> &Dragones_isla);  //funcion que se pide
	~cDragon();
};



