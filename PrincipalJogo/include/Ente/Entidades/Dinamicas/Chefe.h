#ifndef _CHEFE_H_
#define _CHEFE_H_

#include "../Inimigo.h"
#include  "Projetil.h "
namespace Menus{
    class Fase;
}

class Chefe:public Inimigo{
    private:
        Projetil* pProj;
        Menus::Fase* pFase;
        Entidade* pPlataforma;
        bool alarmadoProj;

    public:
        Chefe();
        ~Chefe();
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

        void alarmadoProjetil(int dist);

        void movimentar(const float dt);

        void executar(const float dt);

};

#endif