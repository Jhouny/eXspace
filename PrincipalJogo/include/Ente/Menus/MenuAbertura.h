#ifndef _MENU_ABERTURA_H_
#define _MENU_ABERTURA_H_

#include "Menu.h"
#include "../../ElementosGraficos/Botao.h"
#include "../../Controle/ControleMenu.h"

namespace Menus {
    class MenuAbertura: public Menu {
        private:           
            Controle::ControleMenu pControleMenu; 
        public:
            MenuAbertura();

            ~MenuAbertura();

            void criaBotoes();

            void atualizar(const float dt);

            void renderizar();

            void ativarControle();

            void desativarControle();

            void executar(const float dt);
    };

}

#endif