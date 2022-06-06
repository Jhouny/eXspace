#ifndef _MENU_TRANSICAO_H_
#define _MENU_TRANSICAO_H_void
#include "Menu.h"


namespace Menus{
    class MenuTransicao:public Menu{
        private:
            std::vector<ElementosGraficos::Texto*> lTextos;
            ElementosGraficos::Texto* pTexto;
        public:
            MenuTransicao();
            ~MenuTransicao();
            void ativarControle();

            void desativarControle();

            void criaBotoes();

            void renderizar();

            void atualizar(const float dt);

            void executar(const float dt);
            

    };
}



#endif