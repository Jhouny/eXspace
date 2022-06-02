#include "../../include/Controle/ControleMenu.h"
#include "../../include/Ente/Menus/Menu.h"

namespace Controle{
    ControleMenu::ControleMenu(Menus::Menu* pM):
        Observador(),
        pMenu(pM),
        subir("Up"),
        descer("Down")
    {
        teclasPressionadas.insert(std::pair<std::string,bool>(subir,false));
        teclasPressionadas.insert(std::pair<std::string,bool>(subir,true));
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