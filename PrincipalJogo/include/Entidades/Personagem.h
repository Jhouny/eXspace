#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"

class Personagem:public Entidade {
    protected:
        int vida;
        int dano;
    public:
        Personagem(Coordenada tam, Coordenada pos, int v = 100, int d = 20);  //perguntar da construtora da classe que eh derivada
        ~Personagem();

        const int getVida() const { return vida; }

        void setDano(int d);
        const int getDano() const { return dano; }

        void receberDano(int d);

        virtual void movimentar();

        virtual void executar() = 0;
};

#endif