#include "../../../include/Ente/Menus/MenuJogar.h"

namespace Menus{
    MenuJogar::MenuJogar():
        Menu(),
        pControleMenu(this),
        multiplayer(false)
    {
        setID(Estados::IdEstado::menuJogar);
        setTitulo("JOGAR");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow);
        executar(0);
    }

    MenuJogar::~MenuJogar(){

    }

    void MenuJogar::criaBotoes() {
        //Cria botão de NOVO JOGO
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350), Estados::IdEstado::mercurio , "NOVO JOGO");
        pBotao->ativar();
        pBotaoJogar = pBotao;
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));
        //Cria botões de escolha (Num jogadores e Fase)
        pBotaoAlternador = new ElementosGraficos::BotaoAlternador(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 450));
        pBotaoAlternador->inserirEscolha("FASE UM", static_cast<int>(Estados::IdEstado::mercurio));
        pBotaoAlternador->inserirEscolha("FASE DOIS", static_cast<int>(Estados::IdEstado::netuno));
        pBotaoAlternador->setAlvo(pBotaoJogar, 0);
        pBotaoAlternador->setAtivo(0);
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoAlternador), false));  
        
        pBotaoAlternador = new ElementosGraficos::BotaoAlternador(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 550));
        pBotaoAlternador->inserirEscolha("UM JOGADOR", 0);
        pBotaoAlternador->inserirEscolha("DOIS JOGADORES", 1);
        pBotaoAlternador->setAlvo(pBotaoJogar, 1);
        pBotaoAlternador->setMaquina(pMaq);
        pBotaoAlternador->setAtivo(0);
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoAlternador), false));  


        //Cria Botao de CARREGAR JOGO
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 650), Estados::IdEstado::menuCarregar, "CARREGAR JOGO");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
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
        multiplayer = false;
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