#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

namespace Entidades {
    Projetil::Projetil(Coordenada pos, Coordenada tam, float vx, float vy, int d,  const char* path, ID id):
        Entidade(id,tam,pos,false)
    {
            velocidade.x = vx;
            velocidade.y= vy;
            dano = d;
            textura = path;
            setTexture(textura.c_str());
    }

    Projetil::~Projetil() {
        
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
        if(this->getPosicao().x > 12000||this->getPosicao().x < -1000 || this->getPosicao().y > ALTURA || this->getPosicao().y < 0) {
        setAtivo(false);
        }
    }

    void Projetil::executar(const float dt) {
        movimentar(dt);

        estaAtivo();

        atualizaTexture();
    }
}