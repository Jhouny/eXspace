#include "../../../include/Ente/Menus/Menu.h"
#include "../../../include/ElementosGraficos/Texto.h"
#include "../../../include/Estados/MaquinaEstados.h"

namespace Menus{  
    Menu::Menu():
        Ente(ID::menu),
        Estados::Estado(this),
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
        if(it == botoesAtivos.begin()) {
            it = botoesAtivos.end(); 
        }


        it--; 
        (it->first)->ativar();
        it->second = true;       
    }

    void Menu::descerSelecao(){
        getAtivo();
        it->second = false;
        (it->first)->desativar();
        if(it == --botoesAtivos.end()) {
            it = botoesAtivos.begin();
            it->second = true; 
        } else {
            it++; 
        }
        (it->first)->ativar();
        it->second = true;
    }

    void Menu::entrar(){
        if(relogio.getElapsedTime().asSeconds() > 0.1){
            getAtivo();
            ElementosGraficos::BotaoAlternador* tmp = dynamic_cast<ElementosGraficos::BotaoAlternador*>(it->first);
            if(tmp == NULL)
                getMaquina()->setEstadoAtual((it->first)->getFuncao());
            else
                tmp->proximo();
            reiniciarRelogio();
        }
    }

    void Menu::voltar() {
        if(relogio.getElapsedTime().asSeconds() > 0.1){
            getMaquina()->setEstadoAnterior();
            reiniciarRelogio(); 
        }
    }

    void Menu::setFundoAleatorio() {
        int val = rand() % 9;
        switch (val) {
        case 0:
            setTexture(TEX_FUNDO_UM);
            break;
        case 2:
            setTexture(TEX_FUNDO_DOIS);
            break;
        case 3:
            setTexture(TEX_FUNDO_TRES);
            break;
        case 4:
            setTexture(TEX_FUNDO_QUATRO);
            break;
        case 5:
            setTexture(TEX_FUNDO_CINCO);
            break;
        case 6:
            setTexture(TEX_FUNDO_SEIS);
            break;
        case 7:
            setTexture(TEX_FUNDO_SETE);
            break;
        case 8:
            setTexture(TEX_FUNDO_OITO);
            break;
        default:
            setTexture(TEX_FUNDO_OITO);
            break;
        }
    }

    void Menu::setTexture(const char* path){
        sf::Texture *temp = pGrafico->loadTexture(path);
        fundo.setTexture(*temp);

        float sX = (float)COMPRIMENTO/temp->getSize().x;
        float sY = (float)ALTURA/temp->getSize().y;
        
        fundo.setScale(sX, sY);
    }

    void Menu::setTitulo(const char* titu){
        titulo.setTexto(titu);
    }

    void Menu::ativarControle() {
        pControle.ativar();
    }

    void Menu::desativarControle(){
        pControle.desativar();
    }
}