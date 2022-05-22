#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include"../Personagem.h"
#include "../../Gerenciadores/Grafico.h"


class Jogador: public Personagem {
    private:
        float velocidade[2];
        float aceleracaoY;
        Gerenciadores::Grafico *pGrafico;  // Ponteiro para o gerenciador grafico

    public:
        Jogador(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = jogador);
        ~Jogador();
        
        void setGerenciadorGrafico(Gerenciadores::Grafico *inst) { pGrafico = inst; }

        void setVelocidade(float vx, float vy);
        float *getVelocidade() {return velocidade;}

        void setAceleracao(float acel) {aceleracaoY=acel;}
        float getAceleracao(){return aceleracaoY;}
        
        void estaVivo();

        // Fisica
        void movimentar();
        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void aplicaAcel();
        void atualizaAcel();

        void executar();
};


#endif