#ifndef _MENU_ABERTURA_H_
#define _MENU_ABERTURA_H_

#include "Menu.h"
#include "../../ElementosGraficos/Botao.h"

namespace Menus {
    class MenuAbertura: public Menu{
        private:            
        public:
            MenuAbertura();

            ~MenuAbertura();

            void criaBotoes();

            void atualizar(const float dt);

            void renderizar();

            void executar(const float dt);
    };

}

#endif