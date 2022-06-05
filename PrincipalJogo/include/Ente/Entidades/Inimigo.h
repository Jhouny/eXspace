#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include"../../Auxiliares/stdafx.h"
#include "Personagem.h"

class Jogador;

class Inimigo: public Personagem {
    protected:
        Jogador* pJogador;// vetor de duas posicoes 
        // contador static int para vetor
        bool jogTaPerto;
    public:
        Inimigo(Coordenada tam, Coordenada pos, ID id, bool est, int v = 100, int d = 20);
        
        ~Inimigo();
        void setJogador(Jogador*pJog); //colocar em um vetor de duas posicoes 

        void alarmado(int dist);

        virtual bool estaVivo() {};
        virtual void colisao(Entidade* outraEntidade, Coordenada intersecao) = 0;
        virtual void movimentar(const float dt) = 0;
        virtual void executar(const float dt) = 0;
};



#endif