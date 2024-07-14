#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class cCarreraDeDragones {
public:
    cCarreraDeDragones(vector<cJinete*>& Jinetes_isla);
    void iniciarCarrera();

private:
    vector<cJinete*>& jinetes;
    void contarRegreso();
};

