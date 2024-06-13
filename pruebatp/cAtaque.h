#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class cAtaque
{
private:
	string Tipo, Danio, Alcance;
public:
	cAtaque(string Tipo, string Danio, string Alcance);
	string getTipo();
	string getDanio();
	string getAlcance();
	void setTipo(string Tipo);
	void setDanio(string Danio);
	void setAlcance(string Alcance);
	string to_string();
	friend ostream& operator<<(ostream & os, cAtaque &a);
	~cAtaque();
};

