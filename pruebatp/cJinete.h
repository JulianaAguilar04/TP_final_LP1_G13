#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cPersona.h"

class cDragon;

using namespace std;
enum eResultadoEntrenamiento {
	NoAsistio,
	Aprobado,
	Desaprobado,
	Primero,
	Ultimo,
};

class cJinete:public cPersona
{
private:
	string Caracteristicas;
	vector <cDragon*> misDragones;
	//eResultadoEntrenamiento ResultadoEntrenamiento;

public:
	cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas);
	string to_string();
	void IncorporarDragon();
	/*
	string getNombre();
	string getApellido();
	string getApodo();
	string getFecNac();
	string getCaracteristicas();
	void setNombre(string nuevoNombre);
	void setApellido(string nuevoApellido);
	void setApodo(string nuevoApodo);
	void setFecNac(string nuevaFecNac);
	void setCaracteristicas(string nuevaCaracteristica);
	*/
	~cJinete();
	
};

