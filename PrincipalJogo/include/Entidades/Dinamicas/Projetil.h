#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include"../Entidade.h"
#include"../../Auxiliares/stdafx.h"

class Projetil: public Entidade {
    private:
        float velocidade[2];  //perguntar sobre representaçao uml 
        int dano;
    public:
        Projetil(Coordenada tam, Coordenada pos, float vx = 30, float vy = 0, int d = 20);
        ~Projetil();

        void setVelocidade(float vx, float vy);
        const float* getVelocidade() const { return velocidade; }  // const para ponteiro?

        void setDano(int d);
        const int getDano() const { return dano; }

        void executar();
};

#endif
