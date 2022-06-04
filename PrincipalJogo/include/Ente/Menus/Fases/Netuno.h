#ifndef _NETUNO_H_
#define _NETUNO_H_

#include "../Fase.h"
#include "../../Entidades/Dinamicas/Chefe.h" 

namespace Menus{
    class Netuno: public Fase {
        private:
        //Chefe* pChefe;
            
        public:
            Netuno(Jogador* jog1, Jogador* jog2 = NULL);
            ~Netuno();
            void geraPlataformas(); 
            void geraObstaculos(); 
            void geraInimigos();
            void executar(const float dt);


    };
}

#endif