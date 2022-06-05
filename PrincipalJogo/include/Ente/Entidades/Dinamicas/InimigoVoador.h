#ifndef _INIMIGO_VOADOR_H_
#define _INIMIGO_VOADOR_H_

#include "../Inimigo.h"
#include "Projetil.h"

#define VELOCIDADE_PROJETIL 76800 * TICK_RATE * 2
#define DISTANCIA_ALARME 500
#define TEX_INIMIGO_VOADOR "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoVoador/Still.png"

namespace Menus{
    class Fase;
}

class InimigoVoador:public Inimigo{
    private:
        Projetil* pProj;
        Menus::Fase* pFase;

    public:
        InimigoVoador();
        ~InimigoVoador();

        float getSegundos() {
            return clock.getElapsedTime().asSeconds();
        }

        void reiniciarClock() {
            clock.restart();
        }

        void setFase(Menus::Fase* pF) { pFase = pF; }

        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void atacar();

        void atualiza(const float dt);

        void movimentar(const float dt);

        void executar(const float dt);
};

#endif