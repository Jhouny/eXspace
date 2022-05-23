#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"

#define GRAVIDADE 3

class Personagem:public Entidade {
    protected:
        int vida;
        int dano;
        bool jumping;
        bool vivo;
        float aceleracaoY;
        Coordenada velocidade;

    public:
        Personagem(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = vazio);  //perguntar da construtora da classe que eh derivada
        ~Personagem();

        const int getVida() const { return vida; }

        void setDano(int d);
        const int getDano() const { return dano; }

        void setVelocidade(Coordenada v) { velocidade = v; }
        Coordenada getVelocidade() { return velocidade; }

        void setAceleracao(float acel) { aceleracaoY=acel; }
        float getAceleracao() { return aceleracaoY; }

        void receberDano(int d);

        void setJump(bool state) { jumping = state; }
        const bool getJump() const { return jumping; }

        virtual void estaVivo() = 0;

        virtual void colisao(Entidade* outraEntidade, Coordenada intersecao) = 0;

        virtual void movimentar() = 0;

        virtual void executar() = 0;
};

#endif