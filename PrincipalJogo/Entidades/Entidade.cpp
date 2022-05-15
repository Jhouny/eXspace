#include "Entidade.h"

Entidade::Entidade(Coordenada tam, Coordenada pos):
        Ente(),
        tamanho(tam),
        posicao(pos)
{
}

Entidade::~Entidade() {

}

void Entidade::setPosicao(Coordenada pos) {
    posicao = pos;
}

void Entidade::setPosicao(float x, float y) {
    posicao.setCoordenada(x, y);
}

