#ifndef _BOTAO_H_
#define _BOTAO_H_

#include "ElementoGrafico.h"
#include "Texto.h"

#define TEX_BOTAO_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botao2.png"
#define TEX_BOTAO_NEUTRO "PrincipalJogo/assets/Texturas/Botoes/botao1.png"
#define FONT_TEXTO "PrincipalJogo/assets/Fonts/Starjedi.ttf"

namespace ElementosGraficos {
    class Botao: public ElementoGrafico {
        private:
            bool ativo;
            Texto texto;

        public:
            Botao(Coordenada tam, Coordenada pos, std::string titulo = "");

            ~Botao();

            sf::Text* getTexto() { return texto.getTexto(); }

            void ativar();
            void desativar();

            bool getAtivo() const { return ativo; }

            void atualizarTextura();

            void executar();
    };

} // namespace ElementosGraficos 

#endif