#include "../../include/Entidades/Entidade.h"

Entidade::Entidade(Coordenada tam, Coordenada pos):
    Ente(),
    tamanho(tam),
    posicao(pos),
    shape(Vector2f(tam.getX(),tam.getY()))
{
    shape.setPosition(pos.x,pos.y);
}

Entidade::~Entidade() {

}

void Entidade::setPosicao(Coordenada pos) {
    posicao = pos;
}

void Entidade::setPosicao(float x, float y) {
    posicao.setCoordenada(x, y);
}

