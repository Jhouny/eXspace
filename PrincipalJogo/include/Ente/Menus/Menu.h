#ifndef _MENU_H_
#define _MENU_H_

#define TEX_FUNDO_UM "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo1.jpg"
#define TEX_FUNDO_DOIS "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo2.jpg"
#define TEX_FUNDO_TRES "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo3.jpg"

#include "../Ente.h"
#include "../../Auxiliares/Lista.h "
#include "../../ElementosGraficos/Botao.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Controle/ControleMenu.h"



namespace Menus{
    class Menu: public Ente{
        protected:
            std::map<ElementosGraficos::Botao*, bool> botoesAtivos;
            std::map<ElementosGraficos::Botao*, bool>::iterator it;

            //sf::Sprite fundo;

            Gerenciadores::Grafico* pGrafico;
            Controle::ControleMenu pControle;
            ElementosGraficos::Botao* pBotao;
        public:
            sf::Sprite fundo;
            Menu();

            ~Menu();

            void getAtivo();

            void subirSelecao();

            void descerSelecao();

            void entrar();

            void setFundoAleatorio();

            void setTexture(const char* path);

            virtual void criaBotoes() = 0;

            virtual void renderizar() = 0;

            virtual void atualizar(const float dt) = 0;

            virtual void executar(const float dt) = 0;

    };
}

#endif