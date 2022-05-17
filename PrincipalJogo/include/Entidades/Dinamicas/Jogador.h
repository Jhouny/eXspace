#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include"../Personagem.h"

class Jogador: public Personagem {
    private:
        float velocidade[2];
    public:
        Jogador(Coordenada tam, Coordenada pos, int v = 100, int d = 20);
        ~Jogador();

        void setVelocidade(float vx, float vy);
        void movimentar();
        void colisao(Entidade* outraEntidade);
        void executar();
};

#endif