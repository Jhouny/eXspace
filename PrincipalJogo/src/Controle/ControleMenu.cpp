#include "../../include/Controle/ControleMenu.h"
#include "../../include/Ente/Menus/Menu.h"

namespace Controle{
    ControleMenu::ControleMenu(Menus::Menu* pM):
        Observador(),
        pMenu(pM),
        subir("Up"),
        descer("Down"),
        entrar("Enter")
    {
        teclasPressionadas.insert(std::pair<std::string,bool>(subir, false));
        teclasPressionadas.insert(std::pair<std::string,bool>(descer, false));
        teclasPressionadas.insert(std::pair<std::string,bool>(entrar, false));
    }

    ControleMenu::~ControleMenu(){
        pMenu = NULL;
    }

    void ControleMenu::compartilharTeclaPressionada(std::string tecla){
        if(tecla == subir){
            teclasPressionadas[subir] = true;
            pMenu->subirSelecao();
        }
        if(tecla == descer){
            teclasPressionadas[descer] = true;
            pMenu->descerSelecao();
        }
        if(tecla == entrar){
            teclasPressionadas[entrar] = true;
            pMenu->entrar();
        }

    }
            
    void ControleMenu::compartilharTeclaLiberada(std::string tecla){
         if(tecla == subir){
            teclasPressionadas[subir] = false;
        }
        if(tecla == descer){
            teclasPressionadas[descer] = false;
        }

    }

    void ControleMenu::setMenu(Menus::Menu* menu){

    }




}