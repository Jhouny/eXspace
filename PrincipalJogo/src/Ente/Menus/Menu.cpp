#include "../../../include/Ente/Menus/Menu.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{  
    Menu::Menu():
        Ente(ID::menu),
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        pControle(this),
        titulo(Coordenada(COMPRIMENTO,500.f),Coordenada(COMPRIMENTO/2.f,100.f),"")
        {
            titulo.setCor(sf::Color::Yellow);
            pBotao = NULL;
        }

    Menu::~Menu() {
        pBotao = NULL;
        botoesAtivos.clear();
    }

    void Menu::getAtivo() {
        for(it = botoesAtivos.begin(); it != botoesAtivos.end() && (it->first)->getAtivo() == false; it++);
    }

    void Menu::subirSelecao() {
        getAtivo();
        it->second = false;
        (it->first)->desativar();
        if(it == botoesAtivos.begin()){
            it = botoesAtivos.end(); 
            it--;
        } else {
            it--; 
        }
        (it->first)->ativar();
        it->second = true;       
    }

    void Menu::descerSelecao(){
        getAtivo();
        it->second = false;
        (it->first)->desativar();
        if(it == --botoesAtivos.end()){
            it = botoesAtivos.begin();
            it->second = true; 
        } else {
            it++; 
        }
        (it->first)->ativar();
        it->second = true;
    }

    void Menu::entrar() {}

    void Menu::setFundoAleatorio() {
        int val = rand() % 3;
        switch(val) {
            case 0:
                setTexture(TEX_FUNDO_UM);
                break;
            case 1:
                setTexture(TEX_FUNDO_DOIS);
                break;
            case 2:
                setTexture(TEX_FUNDO_TRES);
                break;
        }
        
    }

    void Menu::setTexture(const char* path){
        sf::Texture *temp = pGrafico->loadTexture(path);
        fundo.setTexture(*temp);

        float sX = (float)COMPRIMENTO/temp->getSize().x;
        float sY = (float)ALTURA/temp->getSize().y;
        cout<< "sX " << sX <<endl;
        cout<< "sY " << sY <<endl;
        
        fundo.setScale(sX, sY);
    }

    void Menu::setTitulo(const char* titu){
        titulo.setTexto(titu);
    }

}