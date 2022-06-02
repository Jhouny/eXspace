#ifndef _BOTAO_H_
#define _BOTAO_H_

#include "ElementoGrafico.h"

#define TEX_BOTAO_ATIVO ""
#define TEX_BOTAO_NEUTRO ""

namespace ElementosGraficos {
    class Botao: public ElementoGrafico {
        private:
            bool ativo;
        public:
            Botao(Coordenada tam, Coordenada pos);

            ~Botao();

            void ativar();

            void atualizarTextura();

            void executar();
    };

} // namespace ElementosGraficos 

#endif