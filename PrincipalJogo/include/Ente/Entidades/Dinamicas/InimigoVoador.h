#ifndef _INIMIGO_VOADOR_H_
#define _INIMIGO_VOADOR_H_

#include "../Inimigo.h"
#include "Projetil.h"

#define VELOCIDADE_PROJETIL 76800 * TICK_RATE * 2
#define DISTANCIA_ALARME 500
#define TEX_INIMIGO_VOADOR "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoVoador/Still.png"
#define TAM_PROJETIL_INI_VOADOR Coordenada(12,12)

namespace Menus::Fases{
    class Fase;
}

namespace Entidades::Personagens {
    class InimigoVoador:public Inimigo{
        private:
            Projetil* pProj;
            Menus::Fases::Fase* pFase;
            float pontoMedio;
        public:
            InimigoVoador();
            ~InimigoVoador();

            void randomizarOscilacao();

            float getSegundos() {
                return clock.getElapsedTime().asSeconds();
            }

            void reiniciarClock() {
                clock.restart();
            }

            float getPontoMedio()const { return pontoMedio; }

            void setFase(Menus::Fases::Fase* pF) { pFase = pF; }

            void colisao(Entidade* outraEntidade, Coordenada intersecao);

            void atacar();

            bool estaVivo();

            void atualiza(const float dt);

            void movimentar(const float dt);

            void executar(const float dt);
    };
}

#endif