#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"

class Personagem:public Entidade {
    protected:
        int vida;
        int dano;
        bool jumping;
    public:
        Personagem(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = vazio);  //perguntar da construtora da classe que eh derivada
        ~Personagem();

        const int getVida() const { return vida; }

        void setDano(int d);
        const int getDano() const { return dano; }

        void receberDano(int d);

        void setJump(bool state) { jumping = state; }
        const bool getJump() const { return jumping; }

        virtual void colisao(Entidade* outraEntidade, Coordenada intersecao) = 0;

        virtual void movimentar() = 0;

        virtual void executar() = 0;
};

#endif