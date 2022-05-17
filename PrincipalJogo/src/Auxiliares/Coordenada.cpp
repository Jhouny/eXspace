#include "../../include/Auxiliares/Coordenada.h"

Coordenada::Coordenada(float xs, float ys):
    x(xs),
    y(ys)
{
}

Coordenada::~Coordenada(){
}

void Coordenada::setCoordenada (float xs, float ys){
    x=xs;
    y=ys;
}

void Coordenada::operator+=(Coordenada op){
    this->x += op.getX();
    this->y += op.getY();
}

void Coordenada::operator-=(Coordenada op){
    this->x -= op.getX();
    this->y -= op.getY();
}

void Coordenada:: operator=(Coordenada op){
    this->x=op.getX();
    this->y=op.getY();
}

Coordenada Coordenada::operator * (float n) {
    this->x *= n;
    this->y *= n;
    return *this;
}

void Coordenada::print() {
    cout << "x = " << x << "  y = " << y << endl;
}