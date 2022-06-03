#ifndef _PONTO_H_
#define _PONTO_H_

#include "ElementoGrafico.h"

#define TEX_PONTO_VAZIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_vazio.png"

namespace ElementosGraficos {
    class Ponto: public ElementoGrafico {
        protected:
            bool preenchido;
        public:
            Ponto(Coordenada tam, Coordenada pos);

            ~Ponto();

            void preencher();

            void limpar();

            virtual void atualizarTextura() = 0;

            virtual void executar();
        };    
} // namespace ElementosGraficos 

#endif