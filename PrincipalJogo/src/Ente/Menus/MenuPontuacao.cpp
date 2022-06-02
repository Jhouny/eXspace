#include "../../../include/Ente/Menus/MenuPontuacao.h"


namespace Menus{
    MenuPontuacao::MenuPontuacao():
        Menu()
    {
        setTitulo("PONTUAÇÃO");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        executar(0);
    }

    MenuPontuacao::~MenuPontuacao() {}

    void MenuPontuacao::criaBotoes(){
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350),"JOGAR");
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 475),"PONTUAÇÃO");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 600),"CONFIGURAÇÕES");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
    }
    
    void MenuPontuacao::executar(const float dt){
        criaBotoes();
    }
}