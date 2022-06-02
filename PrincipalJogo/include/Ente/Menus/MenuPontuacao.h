#ifndef _MENU_PONTUCAO_H_
#define _MENU_PONTUCAO_H_

#define TEX_PONTUACAO ""

#include "Menu.h"
#include "../../Auxiliares/Lista.h"
namespace ElementosGraficos{
    class Texto;
}

namespace Menus{
    class MenuPontuacao: public Menu{
        private:
            Lista<ElementosGraficos::Texto> lTextos;
            ElementosGraficos::Texto* pTexto;
            int pontuacao[10];

        
        public:
            MenuPontuacao();

            ~MenuPontuacao();

            void criaBotoes();

            void criaTextos();

            void atualizar(const float dt);

            void incluir(ElementosGraficos::Texto *texto);

            void renderizar();

            void executar(const float dt);



    };
}
#endif