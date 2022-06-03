#ifndef _MENU_GAME_OVER_H_
#define _MENU_GAME_OVER_H_

#include "Menu.h"
#include "../../Auxiliares/Lista.h"
#include "../../Controle/ControleTexto.h"

namespace ElementosGraficos{
    class Texto;
}


namespace Menus{
    class MenuGameOver: public Menu{
        private:
        Lista<ElementosGraficos::Texto> lTextos;
        ElementosGraficos::Texto* pTexto;
        Controle::ControleTexto pControleTexto;
        public:
            MenuGameOver();
            ~MenuGameOver();

            void criaBotoes();

            void criaTextos();

            void renderizar();

            void atualizar(const float dt);

            void incluir(ElementosGraficos::Texto *texto);

            void executar(const float dt);
    };
}

#endif