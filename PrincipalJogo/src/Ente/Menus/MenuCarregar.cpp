#include"../../../include/Ente/Menus/MenuCarregar.h"
#include "../../ElementosGraficos/Botao.h"

#define SAVES_PATH "PrincipalJogo/saves/jogos"
namespace Menus{
    MenuCarregar::MenuCarregar():
        Menu(),
        pControleMenu(this)
    {
        setTitulo("CARREGAR JOGO:");

    }
            
    MenuCarregar::~MenuCarregar(){}

    void MenuCarregar::leCaminhoArquivos(){
        for (const auto & entry : fs::directory_iterator(SAVES_PATH)){   
            vectorCaminhos.emplace_back(entry.path().string());
        }
    }

    void MenuCarregar::ativarControle(){
        pControleMenu.ativar();
    }

    void MenuCarregar::desativarControle(){
        pControleMenu.desativar();
    }

    void MenuCarregar::criaBotoes() {
        botoesAtivos.clear();
        for(int i = 0; i < 5; i++){
            pBotaoPath = new ElementosGraficos::BotaoPath(Coordenada(COMPRIMENTO/2.f - 125.f, 150 + 1*i ));
            pBotaoPath->setTitulo(vectorCaminhos[i]);
            if(i == 0)
                botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoPath), true));
            else
                botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoPath),false));
        }

    }

    void MenuCarregar::renderizar() {
        
    }

    void MenuCarregar::atualizar(const float dt){

    }

    void MenuCarregar::executar(const float dt){
        leCaminhoArquivos();

    }
}