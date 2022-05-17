#include "../../../include/Entidades/Estaticas/Plataforma.h"

Plataforma::Plataforma(Coordenada tam,Coordenada pos):
    Entidade(tam, pos) {
    shape.setFillColor(Color::Magenta);
}
Plataforma::~Plataforma(){

}
void Plataforma::executar() {

}