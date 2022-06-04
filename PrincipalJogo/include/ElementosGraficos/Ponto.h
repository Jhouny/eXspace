#ifndef _PONTO_H_
#define _PONTO_H_

#include "ElementoGrafico.h"

#define TEX_PONTO_VAZIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_vazio.png"

namespace ElementosGraficos {
    enum PontoID {
        indef = 0,
        coracao,
        inimigoAbatido
    };
    class Ponto: public ElementoGrafico {
        protected:
            bool preenchido;
            PontoID pId;
        public:
            Ponto(Coordenada tam, Coordenada pos);

            ~Ponto();

            PontoID getPontoID() const { return pId; }

            void preencher();

            void limpar();

            virtual void atualizarTextura() = 0;

            virtual void executar();
        };    
} // namespace ElementosGraficos 

#endif