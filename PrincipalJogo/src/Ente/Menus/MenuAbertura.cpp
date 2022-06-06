#include "../../../include/Ente/Menus/MenuAbertura.h"


namespace Menus {
    MenuAbertura::MenuAbertura():
        Menu(),
        pControleMenu(this)
       {
        setID( Estados::IdEstado::menuAbertura);
        setTitulo("SPACE CONQUERORS");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow ,5);
        executar(0);
    }

    MenuAbertura::~MenuAbertura() {}

    void MenuAbertura::criaBotoes() {
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 600), Estados::IdEstado::menuGameOver, "CONFIGURAÇÕES");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
       
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350), Estados::IdEstado::menuJogar, "JOGAR");
        pBotao->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));
        
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 475), Estados::IdEstado::pontuacao, "PONTUAÇÃO");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
    }

    void MenuAbertura::executar(const float dt) {
        criaBotoes();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }

    void MenuAbertura::renderizar() {
        pGrafico->draw(&fundo, false);
        
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());
    }

    void MenuAbertura::atualizar(const float dt){
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
        
    }

    void MenuAbertura::ativarControle() {
        pControleMenu.ativar();

    }

    void MenuAbertura::desativarControle(){
        pControleMenu.desativar();
    }
}