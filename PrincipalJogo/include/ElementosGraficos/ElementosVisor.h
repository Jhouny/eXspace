#ifndef _ELEMENTOS_VISOR_H_
#define _ELEMENTOS_VISOR_H_

#include "ElementoGrafico.h"
#include "../Ente/Entidades/Dinamicas/Jogador.h"

namespace ElementosGraficos {
    class ElementosVisor: public ElementoGrafico {
        private:
            Jogador* pJog1;
            Jogador* pJog2;

            
        public:
            ElementosVisor();
            
            ~ElementosVisor();
    };    
} // namespace ElementosGraficos 

#endif