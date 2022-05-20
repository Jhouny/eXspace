#include "../../include/Entidades/Entidade.h"

Entidade::Entidade(ID id, Coordenada tam, Coordenada pos):
    Ente(id),
    tamanho(tam),
    posicao(pos),
    shape(sf::Vector2f(tam.getX(),tam.getY()))
{
    shape.setPosition(pos.x,pos.y);
}

Entidade::~Entidade() {

}

void Entidade::setPosicao(Coordenada pos) {
    posicao = pos;
    this->shape.setPosition(pos.x, pos.y);
}

void Entidade::setPosicao(float x, float y) {
    posicao.setCoordenada(x, y);
}

void Entidade::colisao(Entidade* outraEntidade) { };
