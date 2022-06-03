#ifndef _ELEMENTOS_VISOR_H_
#define _ELEMENTOS_VISOR_H_

#include "../Ente/Entidades/Dinamicas/Jogador.h"
#include "Coracao.h"
#include "InimigoAbatido.h"

namespace ElementosGraficos {
    class ElementosVisor {
        private:
            Jogador* pJog1;
            Jogador* pJog2;

            std::vector<Coracao*> vidaJog1;
            std::vector<Coracao*> vidaJog2;
            std::vector<InimigoAbatido*> vidaJog1;
            
        public:
            ElementosVisor(Jogador* jog1, Jogador* jog2 = NULL);
            
            ~ElementosVisor();

            void atualizaPontuacao();

            void executar();


    };    
} // namespace ElementosGraficos 

#endif