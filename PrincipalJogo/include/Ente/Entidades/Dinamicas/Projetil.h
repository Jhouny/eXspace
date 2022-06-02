#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include"../Entidade.h"
#include"../../../Auxiliares/stdafx.h"

#define TEX_PROJETIL "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil.png"

class Projetil: public Entidade {
    private:
        Coordenada velocidade;  
        int dano;
    public:
        Projetil(Coordenada pos, float vx = 30, float vy = 0, int d = 10, ID id = projetil);
        ~Projetil();

        void setVelocidade(float vx, float vy);
        const Coordenada getVelocidade() const { return velocidade; } 
        void setDirecao(){ velocidade.x *= -1;}

        void setDano(int d);
        const int getDano() const { return dano; }

        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaAtivo();

        void movimentar(const float dt);

        void executar(const float dt);
};

#endif
