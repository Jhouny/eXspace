#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "../Personagem.h"
#include "Projetil.h"

#define TEX_JOGADOR "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/Still.png"

class Fase;
class Jogador: public Personagem {
    private:
        Fase* pFase;
        Projetil* proj;

    public:
        Jogador();
        ~Jogador();
        void estaVivo();

        void setFase(Fase* fase){ 
            if(fase)
                pFase=fase;
        }
        float getSegundos() {
            return clock.getElapsedTime().asSeconds();
        }
        void reiniciarClock() {
            clock.restart();
        }

        // Fisica
        void atacar();
        void movimentar();
        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void aplicaAcel();
        void atualizaAcel();

        void executar();
};

#endif