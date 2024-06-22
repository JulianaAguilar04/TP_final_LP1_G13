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
	int Velocidad=0;
	int Resistencia=0;
	vector <string> Habilidades; //agregue velocidad, resistencia, nivel de entrenamiento y habilidades
	/*
	vector<string> EstrategiasAtaque;
	vector<string> EstrategiasDefensa;
	*/
	int NivelEntrenamiento = 1;
	cAtaque *FormadeAtaque;


public:
	//constructor por parametros 
	cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Velocidad, int Resistencia, vector<string>& Habilidades, cAtaque* miAtaque) : Nombre(Nombre), Caracteristica(Caracteristica), Tamano(Tamano), Color(Color), Estado(Estado), Velocidad(Velocidad), Resistencia(Resistencia), Habilidades(Habilidades), NivelEntrenamiento(1), FormadeAtaque(miAtaque) {};
	//constructor por copia
	cDragon(cDragon& Dragoncito);
	string getNombre();
	string getCaracteristica();
	string getTamano();
	string getColor();
	int getResistencia();
	bool getEstado();
	void setCaracteristica(string nuevaCaracteristica);
	void setTamano(string nuevoTamano);
	void setColor(string nuevoColor);
	void setEstado(bool nuevoEstado);	
	void AltaNombre(string Nombre);			//funcion que se pide
	bool Domado();							//funcion que se pide
	string to_string();
	friend ostream& operator<<(ostream& s, cDragon& d);
	void DesarrollarEstrategia(const string& tipo);
	// void AltaDragon(cDragon *dragon); ???
	void Entrenar(const string &tipoEntrenamiento, const cJinete &Jinete);	//funcion que se pide
	void mostrarHabilidades();  
	void Baja(vector<cDragon> &Dragones_isla);  //funcion que se pide
	~cDragon();
};



