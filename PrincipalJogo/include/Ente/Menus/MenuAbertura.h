#ifndef _MENU_ABERTURA_H_
#define _MENU_ABERTURA_H_
#include "Menu.h"

namespace Menus{
    class MenuAbertura: public Menu{
        private:
        public:
            MenuAbertura();
            ~MenuAbertura();
            void executar();
    };
};

#endif