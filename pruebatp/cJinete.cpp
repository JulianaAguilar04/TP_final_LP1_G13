#include "cJinete.h"

string cJinete::to_string() {
    stringstream ss;
    ss << cPersona::to_string();
    ss << "Caracteristicas: " << Caracteristicas << endl;
    ss << "Resultado: " << ResulEntrenamientostring(Resultado) << endl;
    ss << "Numero de Ovejas: " << numeroOvejas << endl;
    return ss.str();
}

void cJinete::mostrarDragones() const {
    cout << "El jinete " << Nombre << " tiene estos dragones:" << endl;
    for (const auto& dragon : misDragones) {
        cout << "-" << dragon->getNombre() << endl;
    }
}

void cJinete::mostrarInfo(ostream& os) const {
    os << "Nombre: " << Nombre << endl;
    os << "Apellido: " << Apellido << endl;
    os << "Apodo: " << Apodo << endl;
    os << "Fecha de nacimiento: " << FecNac << endl;
    os << "Caracteristicas: " << Caracteristicas << endl;
    os << "Resultado: " << ResulEntrenamientostring(Resultado) << endl;
    os << "Fuerza: " << Fuerza << endl;
    os << "Dragones:" << endl;
    for (const auto& dragon : misDragones) {
        os << "- " << dragon->to_string() << endl;
    }
}

ostream& operator<<(ostream& os, const cJinete& j) {
    j.mostrarInfo(os);
    return os;
}

bool cJinete::tieneDragon(cDragon* dragon) {
    for (cDragon* d : misDragones) {
        if (d == dragon) {
            return true;
        }
    }
    return false;
}

string cJinete::getNombre() const {
    return Nombre;
}

ResulEntrenamiento cJinete::getResultado() const {
    return Resultado;
}

vector<cDragon*> cJinete::getMisDragones() {
    return misDragones;
}

void cJinete::IncorporarDragon(cDragon* dragon) {
    misDragones.push_back(dragon);
}

int cJinete::getNumeroOvejas() const {
    return numeroOvejas;
}

cJinete& cJinete::operator+=(int ovejas) {
    numeroOvejas += ovejas;
    return *this;
}

cJinete::~cJinete() {
}
