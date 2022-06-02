#include "../../../../include/Menu/Menu.h"
namespace Menus{  
    Menu::Menu():
        ente(ID::menu),
        pGrafico(Gerenciadores::Grafico::getInstancia())
        {
            pAtual=NULL;
        


        }

    Menu::~Menu() {}

    void Menu::setInicial(){
        for(int i = 0; i < lElemGrafico.getTamanho(); i++){
            if(lElemGrafico[i]->getID() == ID :: botao){
                pAtual=lElemGrafico[i];
                break;
            }
        }
    }

    void Menu::subirSelecao(){
        if(pAtual==lElemGrafico.getInicial()){
            pAtual=lElemGrafico.getUltimo();
        }
        /*else{
            pAtual=lElemGrafico.getAnte();
        }*/

    }

    void Menu::descerSelecao(){
        if(pAtual==lElemGrafico.getUltimo()){
            pAtual=lElemGrafico.getUltimo();
        }
    /*  else{
            pAtual=lElemGrafico.getProx();
        }*/

    }

    void Menu::push(ElementosGraficos::ElementoGrafico* eleGraf){
        lElemGrafico.push(eleGraf);
    }

    void Menu::setTexture(const char* path){
        sf::Texture *temp = pGrafico->loadTexture(path);
        fundo.setTexture(*temp);
        float sX = (float)COMPRIMENTO/temp->getSize().x;
        float sY = (float)ALTURA/temp->getSize().y;
        fundo.setScale(sX, sY);
    }

}