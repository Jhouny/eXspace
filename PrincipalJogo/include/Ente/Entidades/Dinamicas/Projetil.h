#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include"../Entidade.h"
#include"../../../Auxiliares/stdafx.h"

#define TEX_PROJETIL "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil.png"

class Projetil: public Entidade {
    private:
        Coordenada velocidade;  //perguntar sobre representaçao uml 
        int dano;
    public:
        Projetil(Coordenada pos, float vx = 30, float vy = 0, int d = 20, ID id = projetil);
        ~Projetil();

        void setVelocidade(float vx, float vy);
        const Coordenada getVelocidade() const { return velocidade; }  // const para ponteiro?
        void setDirecaoX();



        void setDano(int d);
        const int getDano() const { return dano; }

        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaVivo();

        void movimentar();

        void executar();
};

#endif
