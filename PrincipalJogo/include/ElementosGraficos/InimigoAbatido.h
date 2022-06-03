#ifndef _INIMIGO_ABATIDO_H_
#define _INIMIGO_ABATIDO_H_

#include "Ponto.h"

#define TEX_INIMIGO_ABATIDO_CHEIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_preenchido.png"
#define TEX_INIMIGO_ABATIDO_VAZIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_vazio.png"

namespace ElementosGraficos {
    class InimigoAbatido: public Ponto {
        private:
        public:
            InimigoAbatido(Coordenada tam, Coordenada pos);

            ~InimigoAbatido();

            void atualizarTextura();
    };    
}

#endif