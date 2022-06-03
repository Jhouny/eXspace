#include "../../../include/Ente/Menus/MenuJogar.h"

namespace Menus{
    MenuJogar::MenuJogar():
        Menu()
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
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350), Estados::IdEstado::fase, "NOVO JOGO");
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 450), Estados::IdEstado::selecionarFase, "FASE UM");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
        

        
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 550), Estados::IdEstado::selecionarJogadores, "UM JOGADOR");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));

        
        
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 650), Estados::IdEstado::configuracoes, "CARREGAR JOGO");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
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
            pGrafico->draw((it->first)->getSprite(),false);
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