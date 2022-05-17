#include"../../include/Entidades/Jogador.h"

Jogador::Jogador(Coordenada tam, Coordenada pos, int v, int d):
    Personagem(tam, pos, v, d) {
        velocidade[0] = 0;
        velocidade[1] = 0;
}
Jogador::~Jogador() {
    free(velocidade);
}

void Jogador::setVelocidade(float vx, float vy) {
    velocidade[0] = vx;
    velocidade[1] = vy;
}

void Jogador::movimentar() {
    Coordenada p = this->getPosicao();
    p += X*velocidade[0];
    p += Y*velocidade[1];
    this->setPosicao(p);
}

void Jogador::executar() {
    movimentar();
}