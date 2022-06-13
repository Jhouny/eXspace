#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

namespace Entidades {
    Projetil::Projetil(Coordenada pos, Coordenada tam, float vx, float vy, int d,  const char* path, ID id):
        Entidade(id,tam,pos,false),
        entOrigem(NULL),
        textura(path),
        dano(d)
    {
        velocidade.x = vx;
        velocidade.y= vy;
        setTexture(textura.c_str());
    }

    Projetil::~Projetil() {
        entOrigem = NULL;
    }

    void Projetil::setVelocidade(float vx, float vy) {
        velocidade.x = vx;
        velocidade.y = vy;
    }

    void Projetil::setDano(int d) {
        dano = d;
    }

    void Projetil::colisao(Entidade* outraEntidade, Coordenada intersecao){
        if(outraEntidade->getID() != ID::gasToxico)
            this->setAtivo(false);
    }

    // Muda a posição da ENTIDADE
    void Projetil::movimentar(const float dt) {
        Coordenada p = this->getPosicao();

        p.x += velocidade.x * dt;
        p.y += velocidade.y * dt;

        this->setPosicao(p);
    }

    void Projetil::estaAtivo() {
        Coordenada limite =  pGrafico->getViewBounds();

        if(this->getPosicao().x > limite.x + COMPRIMENTO/2.f || this->getPosicao().x < limite.x - COMPRIMENTO/2.f) {
            setAtivo(false);
        }
        else if(this->getPosicao().y > limite.y + ALTURA/2.f || this->getPosicao().x < limite.y - ALTURA/2.f) {
            setAtivo(false);
        }
        
    }

    void Projetil::executar(const float dt) {
        movimentar(dt);

        estaAtivo();

        atualizaTexture(velocidade);
    }
}