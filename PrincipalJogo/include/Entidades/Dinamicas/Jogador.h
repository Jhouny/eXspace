#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include"../Personagem.h"

class Jogador: public Personagem {
    private:
        float velocidade[2];
        float aceleracaoY;
    public:
        Jogador(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = jogador);
        ~Jogador();
        
        void setVelocidade(float vx, float vy);
        float *getVelocidade() {return velocidade;}

        void setAceleracao(float acel) {aceleracaoY=acel;}
        float getAceleracao(){return aceleracaoY;}
        
        
        void movimentar();
        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void aplicaAcel();
        void atualizaAcel();
        void executar();
};

#endif