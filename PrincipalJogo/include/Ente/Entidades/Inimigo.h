#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include"../../Auxiliares/stdafx.h"
#include "Personagem.h"

class Jogador;

class Inimigo: public Personagem {
    protected:
        Jogador* pJogador;// vetor de duas posicoes 
        // contador static int para vetor
    public:
        Inimigo(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = vazio);
        
        ~Inimigo();
        void setJogador(Jogador*pJog); //colocar em um vetor de duas posicoes 

        virtual void estaVivo() {};
        virtual void colisao(Entidade* outraEntidade, Coordenada intersecao) = 0;
        virtual void movimentar() = 0;
        virtual void executar() = 0;
};



#endif