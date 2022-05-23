#include"../../include/Ente/Ente.h"

int Ente::cont = 0;

Ente::Ente(ID id) {
    this->id = id;
    cont++;
}

Ente::~Ente() {
}