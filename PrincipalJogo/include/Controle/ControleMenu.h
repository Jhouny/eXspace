#ifndef _CONTROLE_MENU_H_
#define _CONTROLE_MENU_H_

#include "Observador.h"

namespace Controle{
    namespace Menus{
         class Menu;
    }

    class ControleMenu: public Observador{
        private:
            Menus::Menu* pMenu;
            std::map<std::string, bool> teclasPressionadas;
            std::string subir;
            std::string descer;
        public:
            ControleMenu(Menus::Menu* pM);

            ~ControleMenu();

            void compartilharTeclaPressionada(std::string tecla);
            
            void compartilharTeclaLiberada(std::string tecla);

            void setMenu(Menus::Menu* menu);
            



    };
}

#endif