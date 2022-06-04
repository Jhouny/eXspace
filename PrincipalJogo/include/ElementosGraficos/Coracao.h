#ifndef _CORACAO_H_
#define _CORACAO_H_

#include "Ponto.h"

#define TEX_CORACAO_CHEIO "PrincipalJogo/assets/Texturas/Lava/lava.png"
#define TEX_CORACAO_VAZIO "PrincipalJogo/assets/Texturas/Coracao/coracao_vazio.png"

#define TAMANHO_PADRAO_CORACAO Coordenada(20, 20)

namespace ElementosGraficos {
    class Coracao: public Ponto {
        private:
        public:
            Coracao(Coordenada pos);

            ~Coracao();

            void atualizarTextura();
    };    
}

#endif