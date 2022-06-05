#ifndef _INIMIGO_ABATIDO_H_
#define _INIMIGO_ABATIDO_H_

#include "Ponto.h"

#define TEX_INIMIGO_ABATIDO_CHEIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_preenchido.png"
#define TEX_INIMIGO_ABATIDO_VAZIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_vazio.png"

#define TAMANHO_PADRAO_INIMIGO_ABATIDO Coordenada(30, 30)

namespace ElementosGraficos {
    class InimigoAbatido: public Ponto {
        private:
        public:
            InimigoAbatido(Coordenada pos, Jogador* jog);

            ~InimigoAbatido();

            void atualizarTextura();
    };    
}

#endif