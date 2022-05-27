#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include"../Personagem.h"

#define TEX_JOGADOR "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/Still.png"


class Jogador: public Personagem {
    private:

    public:
        Jogador(Coordenada pos, int v = 100, int d = 20, ID id = jogador);
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