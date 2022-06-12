#include "../../../include/Ente/Menus/Menu.h"
#include "../../../include/Ente/Menus/MenuPausa.h"
#include "../../../include/Ente/Menus/MenuCarregar.h"
#include "../../../include/ElementosGraficos/Texto.h"
#include "../../../include/Estados/MaquinaEstados.h"
#include "../../../include/ElementosGraficos/BotaoAlternador.h"
#include "../../../include/ElementosGraficos/BotaoSalvar.h"

namespace Menus{  
    Menu::Menu():
        Ente(ID::menu),
        Estados::Estado(this),
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        titulo(Coordenada(COMPRIMENTO,400.f),Coordenada(COMPRIMENTO/2.f,100.f),"")
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
            Menus::MenuPausa* mPausa = dynamic_cast<Menus::MenuPausa*>(this);

            if((it->first)->getFuncao() == Estados::IdEstado::salvarPontuacao) {
                ElementosGraficos::BotaoSalvar* save = dynamic_cast<ElementosGraficos::BotaoSalvar*>(it->first);
                save->salvar();
            } else if((it->first)->getFuncao() == Estados::IdEstado::alternar) {
                ElementosGraficos::BotaoAlternador* alt = dynamic_cast <ElementosGraficos::BotaoAlternador*>(it->first);
                alt->proximo();
            } else if((it->first)->getFuncao() == Estados::IdEstado::salvarJogo) {
                Menus::MenuPausa* menuPause = dynamic_cast<Menus::MenuPausa*>(this);  // So funciona se o IdEstado::salvarJogo so existir no MenuPausa.cpp
                menuPause->salvaEstado();
            } else if(mPausa != NULL && (it->first)->getFuncao() == Estados::IdEstado::indefinido) {
                mPausa->resumirJogo();
            } else if((it->first)->getFuncao() == Estados::IdEstado::carregar) {
                Menus::MenuCarregar* menuCarr = dynamic_cast<Menus::MenuCarregar*>(this);
                menuCarr->carregarFase();
            } else if((it->first)->getFuncao() == Estados::IdEstado::sair) {
                pGrafico->terminar();                
            } else {
                getMaquina()->setEstadoAtual((it->first)->getFuncao());
            }
            reiniciarRelogio();


        }
    }

    void Menu::voltar() {
        if(relogio.getElapsedTime().asSeconds() > 0.3) {
            Menus::Fases::Fase* temp = dynamic_cast<Menus::Fases::Fase*>(this);
            Menus::MenuPausa* mPausa = dynamic_cast<Menus::MenuPausa*>(this);
            if(temp != NULL) {
                temp->pausarFase();
            } else if(mPausa != NULL) {
                mPausa->resumirJogo();
            } else {
                getMaquina()->setEstadoAnterior();
            }
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
}