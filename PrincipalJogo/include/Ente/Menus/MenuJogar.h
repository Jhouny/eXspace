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
            ElementosGraficos::BotaoAlternador* pBotaoAlternador;
            bool multiplayer;
        public:
            MenuJogar();

            ~MenuJogar();

            void setMultiplayer(bool mt) { multiplayer = mt; }
            bool getMultiplayer() const { return multiplayer; }
            
            void criaBotoes();

            void renderizar();

            void atualizar(const float dt);

            void ativarControle();

            void desativarControle();

            void executar(const float dt);

    };
}

#endif
