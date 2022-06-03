#ifndef _BOTAO_H_
#define _BOTAO_H_

#include "ElementoGrafico.h"
#include "Texto.h"
#include "../Estados/Estado.h"

#define TEX_BOTAO_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botao3.png"
#define TEX_BOTAO_NEUTRO "PrincipalJogo/assets/Texturas/Botoes/botao4.png"
#define FONT_TEXTO "PrincipalJogo/assets/Fonts/Starjedi.ttf"


namespace ElementosGraficos {
    class Botao: public ElementoGrafico {
        private:
            bool ativo;
            Texto texto;
            Estados::IdEstado funcao;

        public:
            Botao(Coordenada tam, Coordenada pos, Estados::IdEstado func, std::string titulo = "" );

            ~Botao();

            sf::Text* getTexto() { return texto.getTexto(); }
            
            Estados::IdEstado getFuncao() const { return funcao; }

            void ativar();
            void desativar();

            bool getAtivo() const { return ativo; }

            void atualizarTextura();

            void executar();
    };

} // namespace ElementosGraficos 

#endif