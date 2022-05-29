#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

Projetil::Projetil(Coordenada pos, float vx, float vy, int d, ID id):
    Entidade(id, Coordenada(10,5), pos)
     {
        velocidade.x = vx;
        velocidade.y= vy;
        dano = d;
        setTexture(TEX_PROJETIL);
}

Projetil::~Projetil() {
    
}

void Projetil::setVelocidade(float vx, float vy) {
    velocidade.x = vx;
    velocidade.y = vy;
}

void Projetil:: setDirecaoX(){
    velocidade.x*=-1;
}

void Projetil::setDano(int d) {
    dano = d;
}

void Projetil::colisao(Entidade* outraEntidade, Coordenada intersecao){
    this->setAtivo(false);
}

// Muda a posição da ENTIDADE
void Projetil::movimentar() {
    Coordenada p = this->getPosicao();

    p.x += velocidade.x;
    p.y += velocidade.y;

    this->setPosicao(p);
}

void Projetil::estaVivo() {
    if(this->getPosicao().x > COMPRIMENTO || this->getPosicao().x < 0 ||this->getPosicao().y > ALTURA || this->getPosicao().y < 0) {
        ativo = false;
    }
}

void Projetil::executar() {  
    movimentar();
    estaVivo();
}