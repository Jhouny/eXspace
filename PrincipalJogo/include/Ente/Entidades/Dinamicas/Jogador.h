#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "../Personagem.h"
#include "Projetil.h"
#include "../../../Controle/ControleJogador.h"

#define TEX_JOGADOR "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/Still.png"

class Fase;
class Jogador: public Personagem {
    private:
        Fase* pFase;
        Projetil* proj;
        Controle::ControleJogador pControle;
        bool andando;

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
        void direita();
        void esquerda();
        void pular();

        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void atualiza(const float dt);
        void atualizaAcel();


        void executar(const float dt);
};

#endif