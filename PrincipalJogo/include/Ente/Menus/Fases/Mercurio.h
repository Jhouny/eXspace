#ifndef _MERCURIO_H_
#define _MERCURIO_H_

#include "../Fase.h"

namespace Menus{
    class Mercurio: public Fase {
        private:
        public:
            Mercurio();
            ~Mercurio();
            void geraPlataformas(); 
            void geraObstaculos(); 
            void geraInimigos();





    };
}


#endif