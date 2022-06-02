#ifndef _MENU_PONTUCAO_H_
#define _MENU_PONTUCAO_H_

#define TEX_PONTUACAO ""

#include "Menu.h"

namespace Menus{
    class MenuPontuacao: public Menu{
        private:
        public:
            MenuPontuacao();

            ~MenuPontuacao();

            void criaBotoes();

            void atualizar(const float dt);

            void renderizar();

            void executar(const float dt);



    };
}
#endif