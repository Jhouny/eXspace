#ifndef _MENU_PONTUCAO_H_
#define _MENU_PONTUCAO_H_

#define PONTUACAO_PATH "PrincipalJogo/saves/pontuacao.txt"

#include "Menu.h"
#include "../../Controle/ControleMenu.h"
#include "../../Auxiliares/Lista.h"

namespace ElementosGraficos{
    class Texto;
}

namespace Menus{
    class MenuPontuacao: public Menu{
        private:
            std::vector<ElementosGraficos::Texto*> vTextos;
            ElementosGraficos::Texto* pTexto;
            ElementosGraficos::Texto* pTextoPontuacao;

            Controle::ControleMenu pControleMenu;
        public:
            MenuPontuacao();

            ~MenuPontuacao();

            void criaBotoes();

            void criaTextos();

            void atualizar(const float dt);

            void incluir(ElementosGraficos::Texto *texto);

            void ativarControle();

            void desativarControle();

            void renderizar();

            void executar(const float dt);



    };
}
#endif