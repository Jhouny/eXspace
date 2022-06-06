#ifndef _NETUNO_H_
#define _NETUNO_H_

#include "Fase.h"
#include "../../Entidades/Dinamicas/Chefe.h" 

#define TEX_FUNDO_NETUNO "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_3/game_background_3. 2.png" 

namespace Menus::Fases {
    class Netuno: public Fase {
        private:
        //Entidades::Personagens::Chefe* pChefe;
            
        public:
            Netuno(Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2 = NULL);
            ~Netuno();
            void geraPlataformas(); 
            void geraObstaculos(); 
            void geraInimigos();
            void executar(const float dt);


    };
}

#endif