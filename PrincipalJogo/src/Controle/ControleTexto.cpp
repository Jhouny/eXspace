#include "../../include/Controle/Controletexto.h"
#include "../../include/Ente/Menus/MenuGameOver.h"

namespace Controle{

    ControleTexto::ControleTexto(Menus::MenuGameOver* menu):
        Observador(),
        espaco("Space"),
        apagar("BackSpace"),
        tamMax(20),
        contador(0),
        pMenu(menu)
    {

    }

    ControleTexto::~ControleTexto(){

    }

    void ControleTexto::compartilharTeclaPressionada(std::string tecla) {
        if(this->getAtivo()) {
            if (tecla == "Enter" || tecla == "Right" || tecla == "Left" || 
                tecla == "Up" || tecla == "Down" || tecla == "Escape" || 
                tecla == "Control" || tecla == "Shift" || tecla == "RControl" || 
                tecla == "RShift" || tecla == "Tab"|| tecla == "Unknown") {
                return;
            }
            if(tecla == apagar){
                if(contador >=0)
                    nome.erase(contador--);
            } else if(contador <= tamMax){
                if(tecla == "Space"){
                    nome += " ";
                    contador++;
                } else {
                    nome += tecla;
                    contador++;             
                }
            }
        }
    }

    void ControleTexto::compartilharTeclaLiberada(std::string tecla) {
        if(this->getAtivo()) {
            
        }
    }
    void ControleTexto::apagaNome(){
        nome = "";
        contador = 0;
    }


}