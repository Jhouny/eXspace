#ifndef _MERCURIO_H_
#define _MERCURIO_H_

#include "Fase.h"
#define TEX_FUNDO_MERCURIO "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/fundo5.jpg"
namespace Menus{
    class MenuGameOver;
}

namespace Menus::Fases{
    class Mercurio: public Fase {
        private:
        public:
            Mercurio(/*Menus::MenuGameOver* men,*/ Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2 = NULL);
            ~Mercurio();
            void geraPlataformas();
            void geraObstaculos();
            void geraInimigos();
            void executar(const float dt);
    };
}


#endif