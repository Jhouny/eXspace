#include"../../../include/Entidades/Dinamicas/Jogador.h"

Jogador::Jogador(Coordenada tam, Coordenada pos, int v, int d):
    Personagem(tam, pos, v, d) {
        shape.setFillColor(Color::Green);
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
    Coordenada X(1,0);
    Coordenada Y(0,1);    

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        shape.move(velocidade[0], 0.0f);
        p += X;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        shape.move(-1*velocidade[0], 0.0f);
        p -= X;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        shape.move(0.0f, velocidade[1]);
        p += Y;  
    }
    if (Keyboard::isKeyPressed(Keyboard::W) && jumping == false) {
        shape.move(0.0f, -1*velocidade[1]);
        p -= Y*10;
    }
    this->setPosicao(p);

    /* DEBUG */
    p.print();
}

void Jogador::colisao(Entidade* outraEntidade) {
    /* Checar o tipo da entidade com que colidiu 
       (plataforma, inimigo, obstaculo, ...) 
    */
    Coordenada centerDistance;
    Coordenada intersect;
    centerDistance.x = outraEntidade->getPosicao().x - this->getPosicao().x;
    centerDistance.y = outraEntidade->getPosicao().y - this->getPosicao().y;

    intersect.x = fabs(centerDistance.x) - (this->getTamanho().x / 2.0f + outraEntidade->getTamanho().x / 2.0f);
    intersect.y = fabs(centerDistance.y) - (this->getTamanho().y / 2.0f + outraEntidade->getTamanho().y / 2.0f);
    if (intersect.x < 0.0f && intersect.y < 0.0f) { 
        Coordenada p = this->getPosicao();
        p.y = outraEntidade->getPosicao().y - (outraEntidade->getTamanho().y/2) - (this->getTamanho().y);
        this->setPosicao(p);
    }
}

void Jogador::executar() {
    movimentar();
    Coordenada p = this->getPosicao();
    p.y = p.y + 0.05;
    this->setPosicao(p);
    this->shape.setPosition(p.x, p.y);
}