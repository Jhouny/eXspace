#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "../Personagem.h"
#include "Projetil.h"
#include "../../../Controle/ControleJogador.h"

#define TEX_JOGADOR "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/Still.png"

namespace Menus{
    class Fase;
}

class Jogador: public Personagem {
    private:
        Menus::Fase* pFase;
        Projetil* proj;
        Controle::ControleJogador pControleJogador;

        float pontuacao;
        bool viradoFrente;
        bool estaPulando;
        bool estaAtirando;

    public:
        Jogador();
        ~Jogador();

        bool estaVivo();

        void setFase(Menus::Fase* fase){ 
            if(fase)
                pFase = fase;
        }

        float getSegundos() {
            return clock.getElapsedTime().asSeconds();
        }

        void reiniciarClock() {
            clock.restart();
        }

        void setVida(int vi){ vida = vi; }
        void setPontuacao(float ponto) { pontuacao = ponto; }

        // Fisica
        void atacar();
        void direita();
        void esquerda();
        void pular();
        void parar();
        void pulo(bool estado);
        void ataque(bool estado);

        void colisao(Entidade* outraEntidade,Coordenada intersecao);
        void atualiza(const float dt);
        void atualizaAcel();

        void resetar();

        void ativarControle() {
            pControleJogador.ativar();
        }

        void desativarControle() {
            pControleJogador.desativar();
        }

        void executar(const float dt);
};

#endif