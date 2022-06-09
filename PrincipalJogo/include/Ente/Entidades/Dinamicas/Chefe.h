#ifndef _CHEFE_H_
#define _CHEFE_H_

#include "../Inimigo.h"
#include  "Projetil.h "
#define TEX_CHEFE "PrincipalJogo/assets/Texturas/Entidades/Inimigos/Chefe/Carro.still.png"
#define TEX_CHEFE_ALARMADO "PrincipalJogo/assets/Texturas/Entidades/Inimigos/Chefe/Carro.alarmado.png"
#define TAM_PROJETIL_CHEFE Coordenada(12, 12)

namespace Menus::Fases {
    class Fase;
}
namespace Entidades::Personagens {
    class Chefe:public Inimigo{
        private:
            Projetil* pProj;
            Menus::Fases::Fase* pFase;
            int danoColisao;
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

            void setFase(Menus::Fases::Fase* pF) { pFase = pF; }

            void colisao(Entidade* outraEntidade, Coordenada intersecao);

            void atacar();

            void alarmadoProjetil(int dist);

            void movimentar(const float dt);

            void executar(const float dt);

    };
}
#endif