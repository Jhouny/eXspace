#ifndef _MERCURIO_H_
#define _MERCURIO_H_

#include "../Fase.h"


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