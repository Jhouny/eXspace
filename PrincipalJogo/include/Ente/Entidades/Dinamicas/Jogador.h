#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include"../Personagem.h"


class Jogador: public Personagem {
    private:

    public:
        Jogador(Coordenada tam, Coordenada pos, int v = 100, int d = 20, ID id = jogador);
        ~Jogador();
        
        void estaVivo();

        // Fisica
        void movimentar();
        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void aplicaAcel();
        void atualizaAcel();

        void executar();
};

#endif