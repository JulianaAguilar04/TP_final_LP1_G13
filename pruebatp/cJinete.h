#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cPersona.h"
#include "cDragon.h"

using namespace std;

enum ResulEntrenamiento {
	No_asistio,
	Ultimo,
	Desaprobado,
	Aprobado,
	Primero
};

inline string ResulEntrenamientostring(ResulEntrenamiento resultado)
{
	switch (resultado) {
	case ResulEntrenamiento::Aprobado: return "Aprobado";
	case ResulEntrenamiento::Desaprobado: return "Desaprobado";
	case ResulEntrenamiento::No_asistio: return "No asistio";
	case ResulEntrenamiento::Ultimo: return "Ultimo";
	case ResulEntrenamiento::Primero: return "Primero";
	default: return "No tiene resultado de entrenamiento.";
	}
}

class cJinete : public cPersona {
private:
	string Caracteristicas;
	vector<cDragon*> misDragones;
	ResulEntrenamiento Resultado;
	int numeroOvejas = 0; // Para llevar el conteo de ovejas

public:
	cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, ResulEntrenamiento Resul, int Fuerza)
		: cPersona(Nombre, Apellido, Apodo, FecNac, Fuerza), Caracteristicas(Caracteristicas),Resultado(Resul) {}

	string to_string();
	void incrementarOvejas(int cantidad);
	int getNumeroOvejas() const;
	void mostrarDragones() const;
	void mostrarInfo(ostream& os) const;
	friend ostream& operator<<(ostream& os, const cJinete& j);

	bool tieneDragon(cDragon* dragon);
	string getNombre() const;
	ResulEntrenamiento getResultado() const;
	vector<cDragon*> getMisDragones();
	void IncorporarDragon(cDragon* dragon);

	~cJinete();
};

/* 
LO COMENTO PARA PONERLO MAS LIMPIO Y VER QUE FALLA (15/07 - 15hs )

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cPersona.h"
#include "cDragon.h"

class cJinete:public cPersona
{
private:
	string Caracteristicas;
	vector <cDragon*> misDragones;
	double Efectividad;
	string nombre; 
	int numeroOvejas = 0; // Para llevar el conteo de ovejas
	//eResultadoEntrenamiento ResultadoEntrenamiento;

public:
	cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, double Efectividad, int Fuerza) : cPersona(Nombre, Apellido, Apodo, FecNac, Fuerza), Caracteristicas(Caracteristicas), Efectividad(Efectividad) {};
	cJinete(const string& nombre);
	string to_string();
	void incrementarOvejas(int cantidad);
	int getNumeroOvejas() const;
	void mostrarDragones() const;
	void mostrarInfo(ostream& os) const;
	friend ostream& operator<<(ostream& os, const cJinete& j);

	bool tieneDragon(cDragon* dragon);
	string getNombre()const ;
	double getEfectividad() const;
	vector<cDragon*> getMisDragones();
	void IncorporarDragon(cDragon* dragon);
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
	
	~cJinete();
	
};

*/