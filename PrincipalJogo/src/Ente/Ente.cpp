#include"../../include/Ente/Ente.h"

int Ente::cont = 0;

Ente::Ente(ID id) {
    this->id = id;
    rg = cont;
    cont++;
}

Ente::~Ente() {
}