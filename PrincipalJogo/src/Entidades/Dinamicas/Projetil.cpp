#include"../../../include/Entidades/Dinamicas/Projetil.h"

Projetil::Projetil(Coordenada tam, Coordenada pos, float vx, float vy, int d, ID id):
    Entidade(id, tam, pos) {
        velocidade[0] = vx;
        velocidade[1] = vy;
        dano = d;
}

Projetil::~Projetil() {
    free(velocidade);
}

void Projetil::setVelocidade(float vx, float vy) {
    velocidade[0] = vx;
    velocidade[1] = vy;
}

void Projetil::setDano(int d) {
    dano = d;
}

void Projetil::executar() {  // Muda a posição da ENTIDADE
    Coordenada p = this->getPosicao();
    Coordenada X(1,0);
    Coordenada Y(0,1);
    p += X*velocidade[0];
    p += Y*velocidade[1];

    this->setPosicao(p);
}