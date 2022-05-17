#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include"../Auxiliares/stdafx.h"
#include "Personagem.h"
#include "Dinamicas/Jogador.h"

class Inimigo: public Personagem{
    protected:
        Jogador* pJogador;// vetor de duas posicoes 
        // contador static int para vetor
    public:
        Inimigo(Coordenada tam, Coordenada pos, int v = 100, int d = 20);
        ~Inimigo();
        void setJogador(Jogador*pJog);//colocar em um vetor de duas posicoes 

        virtual void colisao()=0;
        void executar();
};



#endif