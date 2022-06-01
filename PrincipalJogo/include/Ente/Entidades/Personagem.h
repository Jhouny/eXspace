#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"

#define GRAVIDADE 2.5

class Personagem: public Entidade {
    protected:
        int vida;
        int dano;
        bool pulando;
        bool vivo;
        float aceleracaoY;
        Coordenada velocidade;
        sf::Clock clock;

    public:
        Personagem(Coordenada tam, Coordenada pos, bool estatico, int v = 100, int d = 20, ID id = vazio);
        ~Personagem();

        const int getVida() const { return vida; }

        void setDano(int d);
        const int getDano() const { return dano; }
        void receberDano(int d);

        void setVelocidade(Coordenada v) { velocidade = v; }
        Coordenada getVelocidade() const { return velocidade; }

        void setAceleracao(float acel) { aceleracaoY = acel; }
        float getAceleracao() { return aceleracaoY; }

        void setJump(bool estado) { pulando = estado; }
        const bool getPulo() const { return pulando; }

        virtual void atacar() {};

        virtual void estaVivo() = 0;

        virtual void colisao(Entidade* outraEntidade, Coordenada intersecao) = 0;

        virtual void movimentar(const float dt) {};

        virtual void executar(const float dt) = 0;
};

#endif