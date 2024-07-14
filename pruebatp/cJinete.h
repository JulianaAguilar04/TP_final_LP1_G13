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
	int numeroOvejas = 0; // Para llevar el conteo de ovejas
	//eResultadoEntrenamiento ResultadoEntrenamiento;

public:
	cJinete(string Nombre, string Apellido, string Apodo, string FecNac, string Caracteristicas, double Efectividad, int Fuerza) : cPersona(Nombre, Apellido, Apodo, FecNac, Fuerza), Caracteristicas(Caracteristicas), Efectividad(Efectividad) {};
	cJinete(const std::string& nombre);
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
	*/
	~cJinete();
	
};

