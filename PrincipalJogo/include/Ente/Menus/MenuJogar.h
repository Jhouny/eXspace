#ifndef _MENU_JOGAR_
#define _MENU_JOGAR_

#include "Menu.h"
#include "../../ElementosGraficos/Botao.h"

namespace Menus{
    class MenuJogar:public Menu{
        private:
        public:
            MenuJogar();
            ~MenuJogar();
            
            void criaBotoes();

            void renderizar();

            void atualizar(const float dt);

            void executar(const float dt);

    };
}

#endif
