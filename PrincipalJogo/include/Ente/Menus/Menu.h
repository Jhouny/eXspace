#ifndef _MENU_H_
#define _MENU_H_

#include "../Ente.h"
#include "../../Auxiliares/Lista.h "
#include "../../ElementosGraficos/ElementoGrafico.h"
#include "../../Gerenciadores/Grafico.h"
namespace Menus{
    class Menu: public Ente{
        protected:
            ElementosGraficos::ElementoGrafico* pAtual;
            Lista<ElementosGraficos::ElementoGrafico*> lElemGrafico;
            sf::Sprite fundo;
            Gerenciadores::Grafico* pGrafico;
            Controle::ControleMenu pControle;
        public:
            Menu();
            ~Menu();

            void setInicial();

            void subirSelecao();

            void descerSelecao();

            void push(ElementosGraficos::ElementoGrafico* eleGraf);

            void setTexture(const char* path);

            virtual void executar() = 0;
    };
}

#endif