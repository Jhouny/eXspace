#ifndef _MENU_JOGAR_
#define _MENU_JOGAR_

#include "Menu.h"
#include "../../ElementosGraficos/Botao.h"
#include "../../ElementosGraficos/BotaoAlternador.h"
#include "../../Controle/ControleMenu.h" 

namespace Menus{
    class MenuJogar:public Menu{
        private:
            Controle::ControleMenu pControleMenu;
            ElementosGraficos::Botao* pBotaoJogar;
        public:
            MenuJogar();

            ~MenuJogar();
            
            void criaBotoes();

            void renderizar();

            void atualizar(const float dt);

            void ativarControle();

            void desativarControle();

            void executar(const float dt);

    };
}

#endif
