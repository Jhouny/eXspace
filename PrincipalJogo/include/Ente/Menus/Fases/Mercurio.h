#ifndef _MERCURIO_H_
#define _MERCURIO_H_

#include "../Fase.h"

#define TEX_FUNDO_MERCURIO "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_4/game_background_4_fx.png" 

namespace Menus{
    class Mercurio: public Fase {
        private:
    
        public:
            Mercurio(Jogador* jog1, Jogador* jog2 = NULL);
            ~Mercurio();
            void geraPlataformas(); 
            void geraObstaculos();
            void geraInimigos();
            void executar(const float dt);
    };
}


#endif