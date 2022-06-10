#ifndef _MENU_CARREGAR_H_
#define _MENU_CARREGAR_H_

#include "Menu.h"

#include "../../ElementosGraficos/BotaoPath.h"
#include "../../Controle/ControleMenu.h"

namespace Menus{
    class MenuCarregar: public Menu {
        private:
            ElementosGraficos::BotaoPath* pBotaoPath;
            Controle::ControleMenu pControleMenu;
            std::vector<std::string> vectorCaminhos;
            
        public:
            MenuCarregar();

            ~MenuCarregar();

            void leCaminhoArquivos();

            void executar();

            void ativarControle();

            void desativarControle();

            void criaBotoes() ;

            void renderizar() ;

            void atualizar(const float dt);

            void executar(const float dt);
                        

    };
}

#endif