#include "../../../include/Ente/Menus/MenuAbertura.h"


namespace Menus {
    MenuAbertura::MenuAbertura():
        Menu()        
    {
        setTitulo("SPACE CONQUERORS");
        executar(0);
    }

    MenuAbertura::~MenuAbertura() {
        pBotao = NULL;
    }

    void MenuAbertura::criaBotoes() {
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 350),"JOGAR");
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 475),"PONTUAÇÃO");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 600),"CONFIGURAÇÕES");
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
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
}