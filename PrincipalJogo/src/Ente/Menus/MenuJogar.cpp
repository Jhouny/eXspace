#include "../../../include/Ente/Menus/MenuJogar.h"

namespace Menus{
    MenuJogar::MenuJogar():
        Menu(),
        pControleMenu(this)
    {
        setID( Estados::IdEstado::menuJogar);
        setTitulo("JOGAR");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow);
        executar(0);
    }

    MenuJogar::~MenuJogar(){

    }

    void MenuJogar::criaBotoes(){
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350), Estados::IdEstado::mercurio , "NOVO JOGO");
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 450), Estados::IdEstado::indefinido, "FASE UM");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
        
        ElementosGraficos::BotaoAlternador* pBA = new ElementosGraficos::BotaoAlternador(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 550));
        pBA->inserirEscolha("UM JOGADOR");
        pBA->inserirEscolha("DOIS JOGADORES");
        pBA->setAtivo(0);
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBA), false));        

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 650), Estados::IdEstado::indefinido, "CARREGAR JOGO");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
    }

    void MenuJogar::ativarControle() {
        pControleMenu.ativar();
    }
 
    void MenuJogar::desativarControle() {
        pControleMenu.desativar();
    }

    void MenuJogar::executar(const float dt){
        criaBotoes();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }  

    void MenuJogar::renderizar(){
        pGrafico->draw(&fundo, false);
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(), false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());
    }

    void MenuJogar::atualizar(const float dt){
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }
}