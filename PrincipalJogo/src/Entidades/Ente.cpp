#include"../../include/Entidades/Ente.h"

int Ente::cont = 0;

Ente::Ente() {
    id = cont;
    cont++;
}

Ente::~Ente() {
}

void Ente::imprimirID() {
    cout << "ID: " << id << endl;
}