#ifndef _CORACAO_H_
#define _CORACAO_H_

#include "Ponto.h"

#define TEX_CORACAO_CHEIO "PrincipalJogo/assets/Texturas/Coracao/coracao_preenchido.png"
#define TEX_CORACAO_VAZIO "PrincipalJogo/assets/Texturas/Coracao/coracao_vazio.png"

namespace ElementosGraficos {
    class Coracao: public Ponto {
        private:
        public:
            Coracao(Coordenada tam, Coordenada pos);

            ~Coracao();

            void atualizarTextura();
    };    
}

#endif