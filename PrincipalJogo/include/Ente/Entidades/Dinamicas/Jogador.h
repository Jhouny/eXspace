#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "../Personagem.h"
#include "Projetil.h"
#include "../../../Controle/ControleJogador.h"

#define TEX_JOGADOR "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/Still.png"
#define TEX_JOGADOR_2 "PrincipalJogo/assets/Texturas/Entidades/Jogador/3 Cyborg/jogador2.png"
#define TAM_PROJETIL_JOGADOR Coordenada(12,4)
#define VIDA_MAX 200

namespace Menus::Fases{
    class Fase;
}

namespace Entidades::Personagens {
    class Jogador: public Personagem {
        private:
            Menus::Fases::Fase* pFase;
            Projetil* proj;
            Controle::ControleJogador pControleJogador; 

            int pontuacao;
            bool viradoFrente;
            bool estaPulando;
            bool estaAtirando;

        public:
            Jogador();
            ~Jogador();

            bool estaVivo();

            void setFase(Menus::Fases::Fase* fase){ 
                if(fase)
                    pFase = fase;
            }

            float getSegundos() {
                return clock.getElapsedTime().asSeconds();
            }

            void reiniciarClock() {
                clock.restart();
            }

            Controle::ControleJogador* getControle() { return &pControleJogador; }
            
            void setPontuacao(float ponto) { pontuacao = ponto; }
            int getPontuacao() const { return pontuacao; } //Precisa?
            void aumentaPontuacao(ID identificacao);

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

            void resetar(int p = 0);

            void ativarControle() {
                pControleJogador.ativar();
            }

            void desativarControle() {
                pControleJogador.desativar();
            }

            void executar(const float dt);
    };
}

#endif