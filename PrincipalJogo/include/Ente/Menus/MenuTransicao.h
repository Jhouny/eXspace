#ifndef _MENU_TRANSICAO_H_
#define _MENU_TRANSICAO_H_void

#include "Menu.h"
#include "../../Controle/ControleMenu.h"

#define TEX_FUNDO_TRANSICAO "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundoTransicao.jpg"

namespace Menus{
    class MenuTransicao:public Menu{
        private:
            std::vector<ElementosGraficos::Texto*> vTextos; //porque tem?pTexto:Texto*
            
            ElementosGraficos::Texto* pTexto;

            Controle::ControleMenu pControleMenu;
            Estados::IdEstado origem;
            int pontuacaoPrev;

            bool multiplayer;

        public:
            MenuTransicao();

            ~MenuTransicao();

            void setOrigem(Estados::IdEstado orig) { origem = orig; }

            void ativarControle();

            void desativarControle();

            void setPontuacaoPrev(int p) { pontuacaoPrev = p; }
            int getPontuacaoPrev() const { return pontuacaoPrev; }

            void setMultiplayer( bool multi) { multiplayer = multi; }
            bool getMultiplayer() const{ return multiplayer; }

            void criaBotoes();

            void renderizar();

            void atualizar(const float dt);

            void executar(const float dt);
            

    };
}



#endif