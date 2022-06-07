#include "../../../include/Ente/Menus/MenuTransicao.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{
    MenuTransicao::MenuTransicao():
        Menu(),
        pControleMenu(this),
        origem(Estados::IdEstado::indefinido)
    {
        setID(Estados::IdEstado::menuTransicao);
        setTitulo("FASE CONCLUIDA");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow);
        executar(0);
    }

    MenuTransicao::~MenuTransicao() {

    }

    void MenuTransicao::ativarControle() {
        pControleMenu.ativar();
    }

    void MenuTransicao::desativarControle() {
        pControleMenu.desativar();
    }

    void MenuTransicao::criaBotoes() {
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350), origem, "JOGAR NOVAMENTE");
        pBotao->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        // Define a proxima fase
        Estados::IdEstado prox;
        if(origem == Estados::IdEstado::mercurio)
            prox = Estados::IdEstado::netuno;
        else if(origem == Estados::IdEstado::netuno)
            prox = Estados::IdEstado::mercurio;

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 550), prox, "PROXIMA FASE");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));
    }

    void MenuTransicao::renderizar() {
        pGrafico->draw(&fundo, false);
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(), false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());
    }

    void MenuTransicao::atualizar(const float dt) {
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }

    void MenuTransicao::executar(const float dt) {
        criaBotoes();
        setTexture(TEX_FUNDO_TRANSICAO);
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    
    }
}

