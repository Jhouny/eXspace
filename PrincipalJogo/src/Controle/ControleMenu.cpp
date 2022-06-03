#include "../../include/Controle/ControleMenu.h"
#include "../../include/Ente/Menus/Menu.h"

namespace Controle{
    ControleMenu::ControleMenu(Menus::Menu* pM):
        Observador(),
        pMenu(pM),
        subir("Up"),
        descer("Down"),
        entrar("Enter"),
        voltar("Escape")
    {
        teclasPressionadas.insert(std::pair<std::string,bool>(subir, false));
        teclasPressionadas.insert(std::pair<std::string,bool>(descer, false));
        teclasPressionadas.insert(std::pair<std::string,bool>(entrar, false));
        teclasPressionadas.insert(std::pair<std::string,bool>(voltar, false));
    }

    ControleMenu::~ControleMenu(){
        pMenu = NULL;
    }

    void ControleMenu::compartilharTeclaPressionada(std::string tecla){
        cout << "entrouMenu" << endl;
        if(this->getAtivo()) {
            if(tecla == subir) {
                teclasPressionadas[subir] = true;
                pMenu->subirSelecao();
            }
            if(tecla == descer) {
                teclasPressionadas[descer] = true;
                pMenu->descerSelecao();
            }
            if(tecla == entrar) {
                teclasPressionadas[entrar] = true;
                pMenu->entrar();
            }
            if(tecla == voltar) {
                teclasPressionadas[voltar] = true;
                pMenu->voltar();
            }
        }
        cout << "saiuMenu" << endl;
    }
            
    void ControleMenu::compartilharTeclaLiberada(std::string tecla){
        if(this->getAtivo()) {
            if(tecla == subir){
                teclasPressionadas[subir] = false;
            }
            if(tecla == descer){
                teclasPressionadas[descer] = false;
            }
            if(tecla == entrar){
                teclasPressionadas[entrar] = false;
            }
            if(tecla == voltar){
                teclasPressionadas[voltar] = false;
            }
        }
    }

    void ControleMenu::setMenu(Menus::Menu* menu){

    }




}