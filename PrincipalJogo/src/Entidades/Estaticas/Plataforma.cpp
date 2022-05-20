#include "../../../include/Entidades/Estaticas/Plataforma.h"

Plataforma::Plataforma(Coordenada tam, Coordenada pos, ID id):
    Entidade(id, tam, pos) {
    shape.setFillColor(sf::Color::Magenta);
}

Plataforma::~Plataforma() { }

void Plataforma::executar() { }