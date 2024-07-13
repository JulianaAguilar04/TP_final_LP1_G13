#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "cAtaque.h"
using namespace std;

class cJinete;
class cDragon
{
protected:
	string Nombre;
	string Caracteristica;
	string Tamano;
	string Color;
	bool Estado;
	int Resistencia=0;
	vector <string> Habilidades; 
	vector<string> EstrategiasAtaque;
	vector<string> EstrategiasDefensa;
	int NivelEntrenamiento = 1;
	cAtaque *FormadeAtaque;


public:
	//constructor por parametros 
	cDragon(string Nombre, string Caracteristica, string Tamano, string Color, bool Estado, int Resistencia, vector<string>& Habilidades, cAtaque* miAtaque) : Nombre(Nombre), Caracteristica(Caracteristica), Tamano(Tamano), Color(Color), Estado(Estado), Resistencia(Resistencia), Habilidades(Habilidades), NivelEntrenamiento(1), FormadeAtaque(miAtaque) {};
	//constructor por copia
	cDragon(cDragon& Dragoncito);
	string getNombre() const;
	string getCaracteristica() const;
	string getTamano() const;
	string getColor() const;
	int getResistencia() const;
	bool getEstado() const;
	void setCaracteristica(string nuevaCaracteristica);
	void setTamano(string nuevoTamano);
	void setColor(string nuevoColor);
	void setEstado(bool nuevoEstado);	
	void AltaNombre(string Nombre);			
	bool Domado();							//funcion que se pide
	string to_string();
	virtual void DesarrollarEstrategia(const string& tipo);
	static cDragon* AltaDragon();													//funcion que se pide
	virtual void Entrenar(const string tipoEntrenamiento, const cJinete& jinete);	//funcion que se pide
	void mostrarHabilidades();  
	void Baja(vector<cDragon*> &Dragones_isla);  //funcion que se pide
	friend ostream& operator<<(ostream& s, cDragon& d);
	virtual ~cDragon();
};



