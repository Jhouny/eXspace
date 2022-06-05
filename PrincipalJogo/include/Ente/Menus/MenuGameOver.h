#ifndef _MENU_GAME_OVER_H_
#define _MENU_GAME_OVER_H_

#include "Menu.h"
#include "../../Auxiliares/Lista.h"
#include "../../Controle/ControleTexto.h"
#include "../../Controle/ControleMenu.h"

namespace ElementosGraficos{
    class Texto;
}


namespace Menus{
    class MenuGameOver: public Menu{
        private:
        Lista<ElementosGraficos::Texto> lTextos;
        ElementosGraficos::Texto* pTexto;
        Controle::ControleTexto pControleTexto;
        Controle::ControleMenu pControleMenu; 

        std::string nome;

        public:
            MenuGameOver();
            ~MenuGameOver();

            void criaBotoes();

            void criaTextos();

            std::string getNome(){ return nome; }

            void renderizar();

            void atualizar(const float dt);

            void incluir(ElementosGraficos::Texto *texto);

            void ativarControle();

            void desativarControle();

            void executar(const float dt);
    };
}

#endif