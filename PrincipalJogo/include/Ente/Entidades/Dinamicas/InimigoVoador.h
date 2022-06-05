#ifndef _INIMIGO_VOADOR_H_
#define _INIMIGO_VOADOR_H_

#include "../Inimigo.h"
#include "Projetil.h"

namespace Menus{
    class Fase;
}

class InimigoVoador:public Inimigo{
    private:
        Coordenada velocidade;
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

        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void atacar();

        void movimentar(const float dt);

        void executar(const float dt);

};

#endif